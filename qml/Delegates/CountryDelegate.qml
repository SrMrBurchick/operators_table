import QtQuick 2.0
import Base 1.0
import System 1.0
import Delegates 1.0

Rectangle{
    id: root
    height: country.height + operators.height

    Column {
        anchors.leftMargin: Style.countryMargin
        Row {
            id: country
            spacing: Style.countrySpacing
            Image {
                source: Style.normalTriangle
                height: Style.rectangleSize
                width: Style.rectangleSize
                MouseArea {
                    anchors.fill: parent
                    onClicked: {
                        if (0 != operators.height) {
                            operators.height = 0;
                            operators.model = {};
                            parent.source = Style.normalTriangle;
                        } else {
                            operators.model = operators_model;
                            operators.height = operators.count * Style.countryImgSize;
                            parent.source = Style.collapsedTriangle;
                        }
                    }
                }
            }
            BaseDelegate {
                text: name
                imgSource: img
                height: Style.countryImgSize
                width: Style.countryImgSize
                textSize: Style.countryFontSize
            }
        }
        ListModel {
            id: operators_model
            /* TODO: Add operators model */
            ListElement{
                name: "Kokos"
                img: "qrc:qml/img/operators/206_1.png"
                mcc: 2
                mnc: 4
            }
        }
        ListView {
            id: operators
            anchors.top: country.bottom
            height: 0
            delegate: OperatorDelegate{
            }
        }
    }
}
