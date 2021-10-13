import QtQuick 2.15
import QtQuick.Window 2.15

Window {
    id: rootId
    width: 480
    height: 570
    visible: true
    title: qsTr("Игра 2048")
    Rectangle{
        anchors.fill: parent
        radius: 5
        color: "darkgray"
        Grid{
            spacing: 10
            anchors.fill: parent
            topPadding: 10
            bottomPadding: 10
            leftPadding: 10
            rightPadding: 10
            columns: 4
            Rectangle{
                id: bestScore
                color: "gainsboro"
                width: (parent.width - 50)/4
                height: 50
                radius: 5
                border.color: "dimgray"
                Text {
                    id: bScoreText
                    text: qsTr("Рекорд")
                    font.pointSize: 12
                    anchors.centerIn: parent
                }
            }
            Rectangle{
                id: score
                color: "gainsboro"
                width: (parent.width - 50)/4
                height: 50
                radius: 5
                border.color: "dimgray"
                Text {
                    id: scoreText
                    text: qsTr("Счет")
                    font.pointSize: 12
                    anchors.centerIn: parent
                }
            }
            Rectangle{
                id: rules
                color: "lightsteelblue"
                width: (parent.width - 50)/4
                height: 50
                radius: 5
                border.color: "dimgray"
                Text {
                    text: qsTr("Правила")
                    font.pointSize: 12
                    anchors.centerIn: parent
                }
                MouseArea{
                    anchors.fill: parent
                    onClicked: {

                    }
                }
            }
            Rectangle{
                id: beginButton
                color: "lightsteelblue"
                width: (parent.width - 50)/4
                height: 50
                radius: 5
                border.color: "dimgray"
                Text {
                    text: qsTr("Новая Игра")
                    font.pointSize: 12
                    anchors.centerIn: parent
                }
                MouseArea{
                    anchors.fill: parent
                    onClicked: {
                        vchanger.newGame()
                    }
                }
            }

            StaticRect{
                id: rect00
                onXChanged: {
                    dimension0.dX = x;
                }
                onYChanged: {
                    dimension0.dY = y;
                }
            }
            StaticRect{
                id: rect01
                onXChanged: {
                    dimension1.dX = x;
                }
                onYChanged: {
                    dimension1.dY = y;
                }
            }
            StaticRect{
                id: rect02
                onXChanged: {
                    dimension2.dX = x;
                }
                onYChanged: {
                    dimension2.dY = y;
                }
            }
            StaticRect{
                id: rect03
                onXChanged: {
                    dimension3.dX = x;
                }
                onYChanged: {
                    dimension3.dY = y;
                }
            }
            StaticRect{
                id: rect10
                onXChanged: {
                    dimension4.dX = x;
                }
                onYChanged: {
                    dimension4.dY = y;
                }
            }
            StaticRect{
                id: rect11
                onXChanged: {
                    dimension5.dX = x;
                }
                onYChanged: {
                    dimension5.dY = y;
                }
            }
            StaticRect{
                id: rect12
                onXChanged: {
                    dimension6.dX = x;
                }
                onYChanged: {
                    dimension6.dY = y;
                }
            }
            StaticRect{
                id: rect13
                onXChanged: {
                    dimension7.dX = x;
                }
                onYChanged: {
                    dimension7.dY = y;
                }
            }
            StaticRect{
                id: rect20
                onXChanged: {
                    dimension8.dX = x;
                }
                onYChanged: {
                    dimension8.dY = y;
                }
            }
            StaticRect{
                id: rect21
                onXChanged: {
                    dimension9.dX = x;
                }
                onYChanged: {
                    dimension9.dY = y;
                }
            }
            StaticRect{
                id: rect22
                onXChanged: {
                    dimension10.dX = x;
                }
                onYChanged: {
                    dimension10.dY = y;
                }
            }
            StaticRect{
                id: rect23
                onXChanged: {
                    dimension11.dX = x;
                }
                onYChanged: {
                    dimension11.dY = y;
                }
            }
            StaticRect{
                id: rect30
                onXChanged: {
                    dimension12.dX = x;
                }
                onYChanged: {
                    dimension12.dY = y;
                }
            }
            StaticRect{
                id: rect31
                onXChanged: {
                    dimension13.dX = x;
                }
                onYChanged: {
                    dimension13.dY = y;
                }
            }
            StaticRect{
                id: rect32
                onXChanged: {
                    dimension14.dX = x;
                }
                onYChanged: {
                    dimension14.dY = y;
                }
            }
            StaticRect{
                id: rect33
                onXChanged: {
                    dimension15.dX = x;
                }
                onYChanged: {
                    dimension15.dY = y;
                }
            }

        }
    }
    StaticRect{
        id: rectG0
        color: grect0.color
        visible: grect0.visible
        x: grect0.x
        y: grect0.y
        Text {
            id: textG0
            text: grect0.text
            font.pointSize: 24
            anchors.centerIn: parent
        }
    }
        StaticRect{
            id: rectG1
            color: grect1.color
            visible: grect1.visible
            x: grect1.x
            y: grect1.y
            Text {
                id: textG1
                text: grect1.text
                font.pointSize: 24
                anchors.centerIn: parent
            }
        }
    //    ParallelAnimation{

    //        NumberAnimation {
    //            target: rectG01Id
    //            property: "x"
    //            duration: 200
    //            easing.type: Easing.InOutQuad
    //            //from:
    //            //to:
    //        }
    //    }
//    Component.onCompleted: {
//        console.log(rectG1.visible.toString())
//    }
}
