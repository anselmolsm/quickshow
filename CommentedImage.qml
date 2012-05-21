import QtQuick 1.1

Column {
    spacing: 10
    property alias source: image.source
    property alias imageWidth: image.width
    property alias imageHeight: image.height

    property alias description: description.text
    property alias fontColor: description.color
    property alias fontSize: description.font.pixelSize
    property alias font: description.font
    property alias descriptionAlignment: description.horizontalAlignment

    Image {
        id: image
    }

    Text {
        id: description
        horizontalAlignment: Text.AlignHCenter
        width: image.width
    }
}
