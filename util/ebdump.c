/*
 * ������ˡ:
 *     text <book-path> <subbook-index> <number>
 * ��:
 *     text /cdrom 0 10
 * ����:
 *     <book-path> �ǻ��ꤷ�� CD-ROM ���Ҥ�����������ܤ����ӡ���ʸ
 *     ����Ƭ���� <number> ��ʬ��ñ�����������Ϥ��ޤ���
 *
 *     <subbook-index> �ˤϡ������оݤ����ܤΥ���ǥå�������ꤷ��
 *     ��������ǥå����ϡ����Ҥκǽ�����ܤ����� 0��1��2 ... ��
 *     �ʤ�ޤ���
 */
#include "config.h"

#include <glib.h>

#include <stdio.h>
#include <stdlib.h>

#include <eb/eb.h>
#include <eb/error.h>
#include <eb/text.h>

inline gboolean isjis(gchar *buff){
	g_assert(buff != NULL);
	
	if((buff[0] >= 0x21) && (buff[0] <= 0x74) && 
	   (buff[1] >= 0x21) && (buff[1] <= 0x7E))
		return(TRUE);
	return(FALSE);
}


int
main(argc, argv)
int argc;
char *argv[];
{
	EB_Error_Code error_code;
	EB_Book book;
	EB_Subbook_Code subbook_list[EB_MAX_SUBBOOKS];
	int subbook_count;
	int subbook_index;
	char text[EB_SIZE_PAGE];
	ssize_t read_length;
	int text_count;
	int block_no;
	
	gchar *p_hex;
	gchar *p_char;
	gchar hex_buff[512];
	gchar char_buff[512];
	gchar buff[512];
	char *result;
	int i;
	
	/* ���ޥ�ɹ԰���������å���*/
	if (argc != 4) {
		fprintf(stderr, "Usage: %s book-path subbook-index block-number\n",
			argv[0]);
		exit(1);
	}
	
	block_no = strtol(argv[3], NULL, 16);
	
	/* EB �饤�֥��� `book' ��������*/
	eb_initialize_library();
	eb_initialize_book(&book);
	
	/* ���Ҥ� `book' �˷���դ��롣*/
	error_code = eb_bind(&book, argv[1]);
	if (error_code != EB_SUCCESS) {
		fprintf(stderr, "%s: failed to bind the book, %s: %s\n",
			argv[0], eb_error_message(error_code), argv[1]);
		goto die;
	}
	
	/* ���ܤΰ����������*/
	error_code = eb_subbook_list(&book, subbook_list, &subbook_count);
	if (error_code != EB_SUCCESS) {
		fprintf(stderr, "%s: failed to get the subbbook list, %s\n",
			argv[0], eb_error_message(error_code));
		goto die;
	}
	
	/* ���ܤΥ���ǥå����������*/
	subbook_index = atoi(argv[2]);
	
	/*�ָ��ߤ����� (current subbook)�פ����ꡣ*/
	if (eb_set_subbook(&book, subbook_list[subbook_index]) < 0) {
		fprintf(stderr, "%s: failed to set the current subbook, %s\n",
			argv[0], eb_error_message(error_code));
		goto die;
	}
	
	
	if (zio_lseek(&book.subbook_current->text_zio, 
		      (block_no - 1) * EB_SIZE_PAGE, SEEK_SET) == -1) {
		fprintf(stderr, "Failed to seek zio\n");
		goto die;
	}
	
	read_length = zio_read(&book.subbook_current->text_zio, text,
			       EB_SIZE_PAGE);
	if (read_length < 0) {
		fprintf(stderr, "Failed to read zio\n");
		goto die;
	}
	
	
	printf("block number : 0x%x\n\n", block_no);
	
	for( i = 0 ;  i < EB_SIZE_PAGE ; i=i+2){
		
                // ���ɥ쥹��ɽ��
		if((i % 16) == 0){
			p_hex = hex_buff;
			p_char = char_buff;
			sprintf(p_hex, "0x%02x(0x%08x) ", (i / 16), (block_no - 1) * EB_SIZE_PAGE + i);
			p_hex += 17;
			
			sprintf(p_char, " ");
			p_char += 1;
		}
		
		sprintf(p_hex, "%02x ", (unsigned char)text[i]);
		p_hex += 3;
		sprintf(p_hex, "%02x ", (unsigned char)text[i+1]);
		p_hex += 3;
		
		
		if(isjis(&text[i])) {
			*p_char = text[i] | 0x80;
			p_char ++;
			*p_char = text[i+1] | 0x80;
			p_char ++;
			*p_char = '\0';
		} else {
			sprintf(p_char, "..");
			p_char +=2;
		}
		
		if((i % 16) == 14){
			printf("%s", hex_buff);
			printf("%s\n", char_buff);
		}
	}
	
	
        
	/* ���Ҥ� EB �饤�֥������Ѥ�λ��*/
	eb_finalize_book(&book);
	eb_finalize_library();
	exit(0);
	
	/* ���顼ȯ���ǽ�λ����Ȥ��ν�����*/
 die:
	eb_finalize_book(&book);
	eb_finalize_library();
	exit(1);
}
