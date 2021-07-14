# Maintainer: AnzoDK <anton@rosenoern-productions.dk>
pkgname="rpcommon"
provides=('rpcommon')
conflicts=('rpcommon-dev')
pkgver=0.0.1
pkgrel=1
arch=('any')
pkgdesc="A compilation of small and common functions to make the dev life easier"
url="https://github.com/AnzoDK/RPCommon"
makedepends=('git')
source=("git+https://github.com/AnzoDK/RPCommon.git#tag=v${pkgver}")
license=('BSD2')
md5sums=('SKIP')
package()
{
   cd RPCommon
   mkdir -p "$pkgdir/usr/include/RPCommon"
   install -D ./RPCommon/ "$pkgdir/usr/include/"
   #install -D ./LICENSE "${pkgdir}"/usr/share/licenses/$pkgname/LICENSE   
}
