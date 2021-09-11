import QtQuick 2.0
import QtQuick.Controls 2.0
import QtQuick.Layouts 1.12
import System 1.0

ColumnLayout {
    id: root

    property bool empty: true
    property int mcc: 0
    property int mnc: 0
    property string name: ""

    anchors.left: parent.left
    anchors.right: parent.right

    spacing: Style.baseSpacing

    signal close()

    RowLayout {
        Layout.alignment: Qt.AlignLeft
        Layout.rightMargin: Style.editorMargin

        Text {
            text: "Name"
        }
        TextField {
            id: operatorName
            Layout.fillWidth: true
            placeholderText: root.name
        }
    }

    RowLayout {
        Layout.alignment: Qt.AlignLeft
        Layout.rightMargin: Style.editorMargin

        Text {
            text: "MCC"
        }
        Text {
            text: " "
        }
        TextField {
            id: operatorMcc
            Layout.fillWidth: true
            readOnly: !root.empty
            placeholderText: root.mcc
            onEditingFinished: {
                /*TODO: Add signal processing*/
            }
        }
        Rectangle {
            Layout.alignment: Qt.AlignRight
            height: Style.editorIconSize
            width: Style.editorIconSize
            Image {
                anchors.fill: parent
                source: Style.uknown
            }
        }
    }

    RowLayout {
        Layout.alignment: Qt.AlignLeft
        Layout.rightMargin: Style.editorMargin

        Text {
            text: "MNC"
        }
        Text {
            text: " "
        }
        TextField {
            id: operatorMnc
            Layout.fillWidth: true
            readOnly: !root.empty
            placeholderText: root.mnc
            onEditingFinished: {
                /*TODO: Add signal processing*/
            }
        }
    }

    RowLayout {
        Layout.alignment: Qt.AlignRight
        Layout.rightMargin: Style.editorMargin

        Button {
            text: "Save"
            enabled: false
        }
        Button {
            text: "Cancel"
            onClicked: {
                root.close()
            }
        }
    }
}
