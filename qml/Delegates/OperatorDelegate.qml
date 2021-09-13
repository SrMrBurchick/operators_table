import QtQuick 2.0
import Base 1.0
import System 1.0

Item {
    id: root
    height: Style.countryImgSize

    Row {
        spacing: Style.baseSpacing
        anchors.fill: root
        anchors.leftMargin: Style.operatorsMargin
        BaseDelegate {
            text: name
            imgSource: img
            textSize: Style.operatorFontSize
            imgSize: Style.countryImgSize
        }
        BaseText {
            text: "(" + mcc + ", " + mnc + ")"
            font.pixelSize: Style.operatorFontSize
        }
        InteractivePlus {
            plusName: name
            plusMnc: mnc
            plusMcc: mcc
            plusEmpty: false
        }
    }
}
