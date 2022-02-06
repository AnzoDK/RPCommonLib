# Maintainer: AnzoDK <anton@rosenoern-productions.dk>
pkgname="rpcommon"
provides=('rpcommon')
conflicts=('rpcommon-dev')
pkgver=0.2.r71.b07757f
MAJORVERSION=0.2
pkgver()
{
  cd RPCommonLib
  printf "$MAJORVERSION.r%s.%s" "$(git rev-list --count HEAD)" "$(git rev-parse --short HEAD)"
}
pkgrel=1
arch=('any')
pkgdesc="A compilation of small and common functions to make the dev life easier"
url="https://github.com/AnzoDK/RPCommonLib"
makedepends=('git')
source=("git+https://github.com/AnzoDK/RPCommonLib.git#branch=master")
license=('BSD2')
md5sums=('SKIP')
prepare()
{
    echo -e "#pragma once\nRPCOMMON_VERSION $pkgver" > RPCommonLib/RPCommon/version.h 
}
package()
{
   cd RPCommonLib
   make
   ./test.out
   if [ $? -ne 0 ]
   then
   	echo "Tests Failed!! - Dying!"
   	exit 1
   fi
   mkdir -p "$pkgdir/usr/include/RPCommon"
   install -D ./RPCommon/* "$pkgdir/usr/include/RPCommon/"
   #install -D ./LICENSE "${pkgdir}"/usr/share/licenses/$pkgname/LICENSE   
}
