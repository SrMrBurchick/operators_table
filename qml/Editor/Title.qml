import QtQuick 2.0
import System 1.0

Item {
    id: root

    anchors.left: parent.left
    anchors.right: parent.right
    height: Style.editorIconSize

    property string img: Style.uknown

    Image {
        height: Style.editorIconSize
        width: Style.editorIconSize
        source: root.img
    }

    Text {
        anchors.horizontalCenter: root.horizontalCenter
        text: Style.editorTitle
        font.bold: true
    }
}

