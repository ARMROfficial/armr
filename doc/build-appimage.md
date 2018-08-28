## HOWTO - Packaging ARMR QT wallet with AppImage

Right now there's no easy way to distribute the [ARMR](https://armr.network/) QT graphical wallet to Linux users, being the only option to compile it oneself from sources. Many Linux users are technically skilled and have no problems with the typical command line instructions, but it’d be desirable to have an easier way of distribution. In this tutorial we’ll cover how to achieve that with [AppImage](https://appimage.org/).

### What’s an AppImage?

Quoting [their wiki](https://github.com/AppImage/AppImageKit/wiki#-what-is-an-appimage):

> An AppImage is a downloadable file for Linux that contains an application and everything the application needs to run (e.g., libraries, icons, fonts, translations, etc.) that cannot be reasonably expected to be part of each target system.

So, from the user’s perspective, it’s an easier to use distribution system:

* no need to know which is the adequate package format (.deb, .rpm)
* no need to add new sources to the system repositories
* no need to resolve unmet dependencies

### Packaging ARMR wallet

Once we have compiled and linked the QT ARMR wallet by following the [instructions provided on GitHub](https://github.com/armr/armr/blob/master/doc/build-unix.txt), the following steps must be applied to obtain an AppImage; the `armr` folder is where the GitHub sources were previously downloaded:

```shell
$ mkdir -p armr/dist/usr/bin
$ cd armr/dist
$ cp ../src/qt/ARMR-qt usr/bin/
$ nano ARMR-qt.desktop
 — — — — — — — — — — — — — —
[Desktop Entry]
Version=1.0
Type=Application
Name=ARMR wallet
Exec=AppRun %F
Icon=ARMR
Categories=Network;
 — — — — — — — — — — — — — —
$ wget https://raw.githubusercontent.com/armr/armr/master/src/qt/res/icons/ARMR.png
$ wget https://github.com/probonopd/linuxdeployqt/releases/download/continuous/linuxdeployqt-continuous-x86_64.AppImage
$ chmod a+x linuxdeployqt-continuous-x86_64.AppImage
$ sudo apt install qt5-default qt5-qmake
$ ./linuxdeployqt-continuous-x86_64.AppImage usr/bin/ARMR-qt -appimage -bundle-non-qt-libs -verbose=2
```

To get an insight about these steps, I’ll explain them in order:
1. We create a folder `dist` to contain the packaging results, with an structure following the [FHS](https://wiki.linuxfoundation.org/lsb/fhs) conventions
1. We copy to the `usr/bin` folder the `ARMR-qt` executable that we previously obtained by compiling and linking
1. We create a `.desktop` file for the package, configured to invoke the AppRun utility provided by AppImage
1. We download from GitHub an icon for the binary package
1. We get the `linuxdeployqt` utility that serves to create the AppImage, and make it executable
1. We ensure that `qt5-qmake` is installed, and make it the default
1. Finally, we create the AppImage

In this way, we obtain a file named `ARMR_wallet-x86_64.AppImage`, that can be distributed without worrying about dependencies; the only step needed to get it running is making it executable:

```shell
$ chmod a+x ARMR_wallet-x86_64.AppImage
$ ./ARMR_wallet-x86_64.AppImage
```
