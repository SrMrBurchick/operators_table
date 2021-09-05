import QtQuick 2.0
import Base 1.0
import Delegates 1.0

ListView {
    id: root
    anchors.fill: parent
    model: ListModel {
        /* Test Model TODO: Add cpp model */
        ListElement {
            country: "Japan"
            countryImg: "qrc:/qml/img/countries/JP.png"
        }
    }
    delegate: CountryDelegate {
        name: country
        img: countryImg
    }
}
