import QtQuick 2.0
import Base 1.0
import System 1.0
import Delegates 1.0

Column {
    id: root
    width: parent.width

    property bool colapse: true

    BaseDelegate {
        id: country
        text: name
        imgSource: img
        textSize: Style.countryFontSize
    }
}
