Name: vcuda
Version: %{version}
Release: %{commit}%{?dist}
Summary: GPU virtual device library

License: MIT
Source: vcuda.tar.gz

Requires: systemd-units

%define pkgname %{name}-%{version}-%{release}

%description
GPU virtual device library

%prep
%setup

%install
install -d $RPM_BUILD_ROOT/%{_libdir}
install -d $RPM_BUILD_ROOT/%{_bindir}

install -p -m 755 libcuda-control.so $RPM_BUILD_ROOT/%{_libdir}/
install -p -m 755 nvml-monitor $RPM_BUILD_ROOT/%{_bindir}/

%clean
rm -rf $RPM_BUILD_ROOT

%files
/%{_libdir}/libcuda-control.so
/%{_bindir}/nvml-monitor

%post
ldconfig

%postun
ldconfig
