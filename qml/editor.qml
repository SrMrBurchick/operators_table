import QtQuick 2.12
import QtQuick.Window 2.12
import System 1.0
import Editor 1.0

Window {
    id: root

    property bool empty: true
    property int mcc: 0
    property int mnc: 0
    property string name: ""

    visible: true
    width: Style.editorWidth
    height: Style.editorHeight

    flags: Qt.FramelessWindowHint

    Item {
        anchors.fill: parent
        Title {
            anchors.top: parent.top
            id: _title
        }

        Body {
            id: _body
            anchors.top: _title.bottom
            name: root.name
            empty: root.empty
            mcc: root.mcc
            mnc: root.mnc
            onClose: {
                root.close();
            }
        }
    }
}
