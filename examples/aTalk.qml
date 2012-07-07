import QtQuick 1.1
import "qrc:/quickshow"

Presentation {
    id: root

    enableMouse: false

    ImageSlide {
        source: "resources/cover.png"
        title: "Qt for Games"
        authors: "Authors"
        date: "MM DD, YYYY"
    }

    RegularSlide {
        title: "Agenda"

        content: [
            "Amazing topic 1",
            "Amazing topic 2",
            "Amazing topic 3",
            "Amazing topic 4"
        ]
    }

    DividerSlide {
        centeredText: "Amazing Topic 1"
    }

    RegularSlide {
        title: "Amazing Topic 1"
        content: [
            "Bla",
            "Bla",
            "Bla"
        ]
    }

    RegularSlide {
        title: "Chicken"
        CodeSection {
            anchors.left: parent.left
            width: parent.width / 1.3
            text: "
int main() {
    printf(\"Hello World!\n\");
    return 0;
}
"
        }
    }

    DividerSlide {
        centeredText: "Amazing Topic 2"
    }

    RegularSlide {
        title: "Amazing Topic 2"
        centeredText: "It's unbeliveable"
    }

    RegularSlide {
        centeredText: "Thank you!"
    }
}
