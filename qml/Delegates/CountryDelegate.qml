import QtQuick 2.0
import Base 1.0
import System 1.0
import Delegates 1.0
import Operators 1.0

Rectangle{
    id: root
    height: country.height + operators.height

    property bool collapsed: false

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
                        if (root.collapsed) {
                            root.collapsed = false;
                            operators.height = 0;
                            operators.model = {};
                            parent.source = Style.normalTriangle;
                        } else {
                            root.collapsed = true;
                            console.log("Kek: " + mcc);
                            operators.model = operators_model.createObject(parent, {countryMCC: mcc});
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
        Component {
            id: operators_model
            OperatorModel {
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
