import QtQuick 2.0
import System 1.0

import Base 1.0

Row {
    id: root
    property string text
    property int textSize
    property int imgSize
    property string imgSource

    spacing: Style.baseSpacing
    Rectangle {
        height: root.imgSize
        width: root.imgSize
        Image {
            anchors.fill: parent
            source: root.imgSource
        }
    }
    BaseText {
        text: root.text
        font.pixelSize: root.textSize
    }
}
