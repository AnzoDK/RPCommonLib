# Maintainer: AnzoDK <anton@rosenoern-productions.dk>
pkgname="rpcommon-dev"
provides=('rpcommon')
conflicts=('rpcommon')
pkgver=0.2.r107.f8ab726
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
source=("git+https://github.com/AnzoDK/RPCommonLib.git#branch=dev")
license=('BSD2')
md5sums=('SKIP')
prepare()
{
    echo -e "#pragma once\n#define RPCOMMON_VERSION \"$pkgver\"" > RPCommonLib/RPCommon/version.h
    LAST=$(cut -d "." -f3 <<< $pkgver);
    NUMERIC=$(expr ${pkgver:0:1} \* 10 + ${pkgver:2:1} \* 5 + ${LAST:1})
    
    echo -e "#define RPCOMMON_VERSION_NR ${NUMERIC}" >> RPCommonLib/RPCommon/version.h
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
    ./test_ex.out
   if [ $? -ne 0 ]
   then
   	echo "Tests Failed!! - Dying!"
   	exit 1
   fi
   mkdir -p "$pkgdir/usr/include/RPCommon"
   install -D ./RPCommon/* "$pkgdir/usr/include/RPCommon/"
   #install -D ./LICENSE "${pkgdir}"/usr/share/licenses/$pkgname/LICENSE   
}
