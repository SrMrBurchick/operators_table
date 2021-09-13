import QtQuick 2.0
import QtQuick.Controls 2.0
import QtQuick.Layouts 1.12
import System 1.0
import DBComponent 1.0
import SystemComponent 1.0

Item {
    id: root

    anchors.fill: parent

    property bool empty: true
    property int mcc: 0
    property int mnc: 0
    property string name: ""

    signal close()

    Item {
        id: _title

        anchors.left: parent.left
        anchors.right: parent.right
        height: Style.editorIconSize

        Image {
            height: Style.editorIconSize
            width: Style.editorIconSize
            source: {
               var path = System.getOperatorImg(
                   root.empty ? operatorMcc.text : root.mcc,
                   root.empty ? operatorMnc.text : root.mnc
               );

               return path;
            }
        }

        Text {
            anchors.horizontalCenter: _title.horizontalCenter
            text: Style.editorTitle
            font.bold: true
        }
    }

    ColumnLayout {
        id: _body

        anchors.left: parent.left
        anchors.right: parent.right
        anchors.top: _title.bottom

        spacing: Style.baseSpacing


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
                    source: {
                        var path = System.getCountryImg(
                            root.empty ? operatorMcc.text : root.mcc
                        );

                        return path;
                    }
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
                function isEnabled() {
                    if (!root.empty) {
                        return operatorName.length > 0;
                    }

                    return operatorName.length > 0 &&
                           operatorMcc.length > 0 &&
                           operatorMnc.length > 0;
                }
                text: "Save"
                enabled: isEnabled()
                onClicked: {
                    if (!root.empty) {
                        Database.updateOperator(operatorName.text, root.mcc, root.mnc);
                    } else {
                        Database.addOperator(operatorName.text, operatorMcc.text, operatorMnc.text);
                    }
                    root.close()
                }
            }
            Button {
                text: "Cancel"
                onClicked: {
                    root.close()
                }
            }
        }
    }
}
