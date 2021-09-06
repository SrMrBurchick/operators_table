import QtQuick 2.0
import System 1.0

import Base 1.0

Row {
    id: root

    property string text
    property int textSize
    property string imgSource

    spacing: Style.baseSpacing

    Image {
        source: root.imgSource
    }
    BaseText {
        text: root.text
        font.pixelSize: root.textSize
    }
}
