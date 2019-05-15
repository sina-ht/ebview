Summary: EPWING CD-ROM dictionary viewer
Name: ebview
Version: 0.3.6
Release: 1
Copyright: GPL
Group: Applications/Text
Source: http://prdownloads.sourceforge.net/ebview/ebview-%{version}.tar.gz
URL: http://ebview.sourceforge.net/
Prefix: /usr
BuildRoot: %{_tmppath}/%{name}-%{version}-root
Summary(ja): EPWING������CD-ROM����򻲾Ȥ��뤿��Υץ����
%description
An EPWING CD-ROM dictionary viewer.
Requeires: gtk2 >= 2.2, eb >= 3.3.2

%description -l ja
EPWING������CD-ROM����򻲾Ȥ��뤿��Υץ����ǡ�������ħ������ޤ���
    * �������ס��������ס��������ס������ס�ʣ�縡�����������Ȥ߹�碌�����ޤ��������ʤɡ����ޤ��ޤʸ�����ˡ���Ѱդ���Ƥ��ޤ���
    * ���ɤ�����:ʣ���μ����쵤�˸������ޤ���
    * �������Ż߲衢ư�衢������ɽ����������Ǥ��ޤ���
    * X���쥯�����μ�ưŪ�ʸ�������ǽ�Ǥ������Ȥ��С�Mozilla�Ǳ�ʸ�ڡ������ɤ�Ǥ�����ˡ�ʬ����ʤ�ñ�줬���ä��餽��ñ������򤹤뤳�ȤǼ�ưŪ�˸�������ޤ���
    * �����μ�ư������Ԥ��ޤ��Τǡ���ñ��β�����ʣ���������ܸ�γ��Ѥʤɤ��������줿���Ǹ�������ޤ���

%prep

%setup -q -c
cd %{name}-%{version}
#%patch1 -p1
cd ..

%build
cd %{name}-%{version}
autoconf
%configure --with-eb-conf=/etc/eb.conf
make
cd ..

%install
cd %{name}-%{version}
%makeinstall
cd ..

%clean
rm -rf ${RPM_BUILD_ROOT}
rm -f *.files

%files
/usr/bin/ebview
/usr/share/locale/ja/LC_MESSAGES/ebview.mo
/usr/share/ebview/about.jp
/usr/share/ebview/about.en
/usr/share/ebview/endinglist.xml
/usr/share/ebview/endinglist-ja.xml
/usr/share/ebview/shortcut.xml
/usr/share/ebview/searchengines.xml
/usr/share/ebview/filter.xml
/usr/share/ebview/help/ja/index.html
/usr/share/ebview/help/ja/menu.html
/usr/share/ebview/help/ja/body.html
/usr/share/ebview/help/en/index.html
/usr/share/ebview/help/en/menu.html
/usr/share/ebview/help/en/body.html
%defattr(-, root, root)
%doc %{name}-%{version}/ChangeLog
%doc %{name}-%{version}/README

%changelog
* Thu May 22 2003 Kenichi Suto <deep_blue@users.sourceforge.net>
- version 0.3.0
* Tue Nov 19 2002 Kenichi Suto <deep_blue@users.sourceforge.net>
- version 0.2.0
* Fri May 17 2002 Kenichi Suto <deep_blue@users.sourceforge.net>
- version 0.1.5
* Sun Feb 24 2002 Kenichi Suto <deep_blue@users.sourceforge.net>
- version 0.1.4
* Fri Jul 27 2001 Kenichi Suto <deep_blue@users.sourceforge.net>
- version 0.1.2
* Fri Jun 22 2001 akira yamada <akira@vinelinux.org>
- Initial packaging.
