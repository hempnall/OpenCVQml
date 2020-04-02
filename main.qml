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
        Button {
            text: "Boo"
            onClicked: {
                im1.filename = "/Users/jameshook/data/cakes.jpg";
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
            filter: Blur {
                width: 15
                height: 15
            }
            onImageChanged: console.log("image changed <<<<");
        }

    }




}


