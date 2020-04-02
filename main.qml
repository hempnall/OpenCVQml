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
            Slider {
                id: slider1
                from: 1
                to: 50
                value: 1
            }
        }
        Mat {
            id: im1
            Layout.fillHeight: true
            Layout.fillWidth: true
            filename: "/Users/jameshook/data/lena.jpg"
        }
        Mat {
            id: lin
            image: im1.image
            Layout.fillHeight: true
            Layout.fillWidth: true
            filter: GuassianBlur {
                width: slider1.value
                height: slider1.value
            }
        }
        Mat {
            id: lin2
            image: lin.image
            Layout.fillHeight: true
            Layout.fillWidth: true
        }
    }




}


