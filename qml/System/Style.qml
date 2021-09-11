pragma Singleton
import QtQuick 2.0

QtObject {
    readonly property int countryFontSize: 14
    readonly property int operatorFontSize: 14
    readonly property int baseSpacing: 2
    readonly property int countrySpacing: 20
    readonly property int rectangleSize: 10
    readonly property int plusSize: 15
    readonly property int plusMargin: 20
    readonly property string normalTriangle: "qrc:qml/img/system/normal_triangle.png"
    readonly property string collapsedTriangle: "qrc:qml/img/system/collapsed_triangle.png"
    readonly property string plus: "qrc:qml/img/system/plus.png"
    readonly property string uknown: "qrc:qml/img/system/uknown.png"

    readonly property int editorWidth: 250
    readonly property int editorHeight: 150
    readonly property int editorIconSize: 20
    readonly property int editorMargin: 5
}
