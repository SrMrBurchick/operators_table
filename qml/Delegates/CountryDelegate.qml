import QtQuick 2.0
import Base 1.0
import System 1.0

Rectangle {
    id: root

    property string name
    property string img

    anchors.left: parent.left
    anchors.right: parent.right

    Row {
        spacing: Style.baseSpacing
        anchors.fill: root
        BaseDelegate {
            text: root.name
            imgSource: root.img
            textSize: Style.countryFontSize
        }
    }
}
