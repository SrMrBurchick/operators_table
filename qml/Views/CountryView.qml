import QtQuick 2.0
import QtQuick.Controls 2.15
import Base 1.0
import Delegates 1.0
import System 1.0
import Countries 1.0

ScrollView {
    id: root
    anchors.fill: parent
    ListView {
        anchors.fill: root
        model: CountryModel {}
        delegate: CountryDelegate {}
    }
}
