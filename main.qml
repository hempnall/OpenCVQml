import QtQuick 2.12
import QtQuick.Window 2.12
import OpenCV 1.0
import QtQuick.Layouts 1.3
import QtQuick.Controls 2.0

Window {
    visible: true
    width: 640
    height: 480
    title: qsTr("Hello World")

    RowLayout {
        anchors.fill: parent
        ColumnLayout {
            Button {
                text: "Boo"
                onClicked: {
                    im1.filename = "/Users/jameshook/data/cakes.jpg";
                }
            }
            Button {
                text: "Match"
                onClicked: {
                    match.matchScale();
                }
            }
            Slider {
                id: slider1
                from: 1
                to: 200
                value: 1
            }
            Slider {
                id: slider2
                from: 1
                to: 200
                value: 1
            }
//            Text {
//                text: gb.transformCount;
//            }
        }
        Mat {
            id: im1
            Layout.fillHeight: true
            Layout.fillWidth: true
            filename: "/Users/jameshook/Desktop/imageHaystack1.png"
           // regions: [ Region { region: Qt.rect(192,152, 182,56) }]
            region: match.region
        }
        Mat {
            id: im2
            Layout.fillHeight: true
            Layout.fillWidth: true
            filename: "/Users/jameshook/Desktop/imageNeedle.png"
        }
        Mat {
            id: nm1
            Layout.fillHeight: true
            Layout.fillWidth: true
            image: match.gsimage
        }
        Mat {
            id: nm2
            Layout.fillHeight: true
            Layout.fillWidth: true
            image: match.gsmatchTemplate
        }

    }

    MatchTemplate {
        id: match
        image: im1.image
        matchTemplate: im2.image
    }
}


