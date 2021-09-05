import QtQuick 2.0
import Base 1.0
import Delegates 1.0
import System 1.0
import Countries 1.0

ListView {
    id: root
    anchors.fill: parent
    spacing: Style.countrySpacing
    model: CountryModel {}
    delegate: CountryDelegate {
    }
}
