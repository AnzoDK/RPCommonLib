# Maintainer: AnzoDK <anton@rosenoern-productions.dk>
pkgname="rpcommon"
provides=('rpcommon')
conflicts=('rpcommon-dev')
pkgver=0.1.11
pkgrel=1
arch=('any')
pkgdesc="A compilation of small and common functions to make the dev life easier"
url="https://github.com/AnzoDK/RPCommonLib"
makedepends=('git')
source=("git+https://github.com/AnzoDK/RPCommonLib.git#tag=v${pkgver}")
license=('BSD2')
md5sums=('SKIP')
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
