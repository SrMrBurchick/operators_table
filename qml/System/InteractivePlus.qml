import QtQuick 2.0
import QtQuick.Controls 2.0

import Base 1.0
import Delegates 1.0
import System 1.0
import Countries 1.0

Image {
    id: root

    property bool empty: true
    property int mcc: 0
    property int mnc: 0
    property string name: ""

    source: Style.plus
    height: Style.plusSize
    width: Style.plusSize

    MouseArea {
        anchors.fill: root
        onClicked: {
            /* TODO: Add opeator editor creation */
        }
    }
}
