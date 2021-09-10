import QtQuick 2.0
import Base 1.0
import System 1.0

Item {
    id: root

    anchors.left: parent.left
    anchors.right: parent.right

    Row {
        spacing: Style.baseSpacing
        anchors.fill: root
        BaseDelegate {
            text: name
            imgSource: img
            textSize: Style.operatorFontSize
        }
        BaseText {
            text: "(" + mcc + ", " + mnc + ")"
            font.pixelSize: Style.operatorFontSize
        }
    }
}