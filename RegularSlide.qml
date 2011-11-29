import QtQuick 1.1

Slide {
    id: root
    property bool logo: true
    color: "black"
    Image {
        visible: root.logo
        anchors.right: parent.right
        anchors.bottom: parent.bottom
        anchors.bottomMargin: -40
        source: "../resources/small_logo.png"
    }
}
