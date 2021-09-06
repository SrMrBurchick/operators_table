import QtQuick 2.12
import QtQuick.Window 2.12
import Views 1.0
import Delegates 1.0

Window {
    id: root
    width: 640
    height: 480
    visible: true
    title: qsTr("Hello World")
    CountryView{}
}
