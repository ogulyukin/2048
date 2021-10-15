import QtQuick 2.15
import QtQuick.Window 2.15
import QtQuick.Controls 2.5
import QtQuick.Dialogs 1.2

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
                Column{
                    anchors.centerIn: parent
                    spacing: 5
                    Text {
                        text: qsTr("Рекорд")
                        height: 12
                        font.pointSize: 12
                        anchors.horizontalCenter: parent.horizontalCenter
                    }
                    Text {
                        id: bScoreText
                        height: 12
                        text: "0"
                        font.pointSize: 12
                        anchors.horizontalCenter: parent.horizontalCenter
                    }
                }
                Connections{
                    target: scorecounter
                    function onBestScoreChanged(){
                        bScoreText.text = scorecounter.bestScore
                    }
                }
            }
            Rectangle{
                id: score
                color: "gainsboro"
                width: (parent.width - 50)/4
                height: 50
                radius: 5
                border.color: "dimgray"
                Column{
                    anchors.centerIn: parent
                    spacing: 5
                    Text {
                        text: qsTr("Счет")
                        height: 12
                        font.pointSize: 12
                        anchors.horizontalCenter: parent.horizontalCenter
                    }
                    Text {
                        id: scoreText
                        height: 12
                        text: "0"
                        font.pointSize: 12
                        anchors.horizontalCenter: parent.horizontalCenter
                    }
                    Connections{
                        target: scorecounter
                        function onScoreChanged(){
                            scoreText.text = scorecounter.score
                        }
                    }
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
                        rulesDialog.open()
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
                Text{
                    text: "0"
                }
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
                Text{
                    text: "3"
                }
                onXChanged: {
                    dimension3.dX = x;
                }
                onYChanged: {
                    dimension3.dY = y;
                }
            }
            StaticRect{
                id: rect10
                Text{
                    text: "4"
                }
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
                Text{
                    text: "7"
                }
                onXChanged: {
                    dimension7.dX = x;
                }
                onYChanged: {
                    dimension7.dY = y;
                }
            }
            StaticRect{
                id: rect20
                Text{
                    text: "8"
                }
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
                Text{
                    text: "11"
                }
                onXChanged: {
                    dimension11.dX = x;
                }
                onYChanged: {
                    dimension11.dY = y;
                }
            }
            StaticRect{
                id: rect30
                Text{
                    text: "12"
                }
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
                Text{
                    text: "15"
                }
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
        Text{
            text: "0"
        }
    }

    NumberAnimation {
        id: a0x
        target: rectG0
        property: "x"
        duration: 500
        easing.type: Easing.OutBounce
        from: grect0.x
        to: grect0.to
        onStopped: {
            grect0.setX = grect0.to;
            //console.log("grect0: Reset X")
        }
    }
    Connections{
        target: grect0
        function onToChanged(){
            //console.log("Got start X animation grect0");
            a0x.from = grect0.x
            a0x.to =  grect0.to;
            a0x.restart();
        }
    }

    NumberAnimation {
        id: a0y
        target: rectG0
        property: "y"
        duration: 500
        easing.type: Easing.OutBounce
        from: grect0.y
        to: grect0.toY
        onStopped: {
            grect0.setY = grect0.toY;
            //console.log("grect0: Reset Y")
        }
    }
    Connections{
        target: grect0
        function onToYChanged(){
            //console.log("Got start Y animation grect0");
            a0y.from = grect0.y
            a0y.to =  grect0.toY;
            a0y.restart();
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
        Text{
            text: "1"
        }
    }

    NumberAnimation {
        id: a1x
        target: rectG1
        property: "x"
        duration: 500
        easing.type: Easing.OutBounce
        from: grect1.x
        to: grect1.to
        onStopped: {
            grect1.setX = grect1.to;
            //console.log("grect1: Reset X")
        }
    }
    Connections{
        target: grect1
        function onToChanged(){
            //console.log("Got start X animation grect1");
            a1x.from = grect1.x
            a1x.to =  grect1.to;
            a1x.restart();
        }
    }

    NumberAnimation {
        id: a1y
        target: rectG1
        property: "y"
        duration: 500
        easing.type: Easing.OutBounce
        from: grect1.y
        to: grect1.toY
        onStopped: {
            grect1.setY = grect1.toY;
            //console.log("grect1: Reset Y")
        }
    }
    Connections{
        target: grect1
        function onToYChanged(){
            //console.log("Got start Y animation grect1");
            a1y.from = grect1.y
            a1y.to =  grect1.toY;
            a1y.restart();
        }
    }

    StaticRect{
        id: rectG2
        color: grect2.color
        visible: grect2.visible
        x: grect2.x
        y: grect2.y
        Text {
            id: textG2
            text: grect2.text
            font.pointSize: 24
            anchors.centerIn: parent
        }
        Text{
            text: "2"
        }
    }

    NumberAnimation {
        id: a2x
        target: rectG2
        property: "x"
        duration: 500
        easing.type: Easing.OutBounce
        from: grect2.x
        to: grect2.to
        onStopped: {
            grect2.setX = grect2.to;
            //console.log("grect2: Reset X")
        }
    }
    Connections{
        target: grect2
        function onToChanged(){
            //console.log("Got start X animation grect2");
            a2x.from = grect2.x
            a2x.to =  grect2.to;
            a2x.restart();
        }
    }

    NumberAnimation {
        id: a2y
        target: rectG2
        property: "y"
        duration: 500
        easing.type: Easing.OutBounce
        from: grect2.y
        to: grect2.toY
        onStopped: {
            grect2.setY = grect2.toY;
            //console.log("grect2: Reset Y")
        }
    }
    Connections{
        target: grect2
        function onToYChanged(){
            //console.log("Got start Y animation grect2");
            a2y.from = grect2.y
            a2y.to =  grect2.toY;
            a2y.restart();
        }
    }

    StaticRect{
        id: rectG3
        color: grect3.color
        visible: grect3.visible
        x: grect3.x
        y: grect3.y
        Text {
            id: textG3
            text: grect3.text
            font.pointSize: 24
            anchors.centerIn: parent
        }
        Text{
            text: "3"
        }
    }

    NumberAnimation {
        id: a3x
        target: rectG3
        property: "x"
        duration: 500
        easing.type: Easing.OutBounce
        from: grect3.x
        to: grect3.to
        onStopped: {
            grect3.setX = grect3.to;
            //console.log("grect3: Reset X")
        }
    }
    Connections{
        target: grect3
        function onToChanged(){
            //console.log("Got start X animation grect3");
            a3x.from = grect3.x
            a3x.to =  grect3.to;
            a3x.restart();
        }
    }

    NumberAnimation {
        id: a3y
        target: rectG3
        property: "y"
        duration: 500
        easing.type: Easing.OutBounce
        from: grect3.y
        to: grect3.toY
        onStopped: {
            grect3.setY = grect3.toY;
            //console.log("grect3: Reset Y")
        }
    }
    Connections{
        target: grect3
        function onToYChanged(){
            //console.log("Got start Y animation grect3");
            a3y.from = grect3.y
            a3y.to =  grect3.toY;
            a3y.restart();
        }
    }

    StaticRect{
        id: rectG4
        color: grect4.color
        visible: grect4.visible
        x: grect4.x
        y: grect4.y
        Text {
            id: textG4
            text: grect4.text
            font.pointSize: 24
            anchors.centerIn: parent
        }
        Text{
            text: "4"
        }
    }

    NumberAnimation {
        id: a4x
        target: rectG4
        property: "x"
        duration: 500
        easing.type: Easing.OutBounce
        from: grect4.x
        to: grect4.to
        onStopped: {
            grect4.setX = grect4.to;
            //console.log("grect4: Reset X")
        }
    }
    Connections{
        target: grect4
        function onToChanged(){
            //console.log("Got start X animation grect4");
            a4x.from = grect4.x
            a4x.to =  grect4.to;
            a4x.restart();
        }
    }

    NumberAnimation {
        id: a4y
        target: rectG4
        property: "y"
        duration: 500
        easing.type: Easing.OutBounce
        from: grect4.y
        to: grect4.toY
        onStopped: {
            grect4.setY = grect4.toY;
            //console.log("grect4: Reset Y")
        }
    }
    Connections{
        target: grect4
        function onToYChanged(){
            //console.log("Got start Y animation grect4");
            a4y.from = grect4.y
            a4y.to =  grect4.toY;
            a4y.restart();
        }
    }

    StaticRect{
        id: rectG5
        color: grect5.color
        visible: grect5.visible
        x: grect5.x
        y: grect5.y
        Text {
            id: textG5
            text: grect5.text
            font.pointSize: 24
            anchors.centerIn: parent
        }
        Text{
            text: "5"
        }
    }

    NumberAnimation {
        id: a5x
        target: rectG5
        property: "x"
        duration: 500
        easing.type: Easing.OutBounce
        from: grect5.x
        to: grect5.to
        onStopped: {
            grect5.setX = grect5.to;
            //console.log("grect5: Reset X")
        }
    }
    Connections{
        target: grect5
        function onToChanged(){
            //console.log("Got start X animation grect5");
            a5x.from = grect5.x
            a5x.to =  grect5.to;
            a5x.restart();
        }
    }

    NumberAnimation {
        id: a5y
        target: rectG5
        property: "y"
        duration: 500
        easing.type: Easing.OutBounce
        from: grect5.y
        to: grect5.toY
        onStopped: {
            grect5.setY = grect5.toY;
            //console.log("grect5: Reset Y")
        }
    }
    Connections{
        target: grect5
        function onToYChanged(){
            //console.log("Got start Y animation grect5");
            a5y.from = grect5.y
            a5y.to =  grect5.toY;
            a5y.restart();
        }
    }

    StaticRect{
        id: rectG6
        color: grect6.color
        visible: grect6.visible
        x: grect6.x
        y: grect6.y
        Text {
            id: textG6
            text: grect6.text
            font.pointSize: 24
            anchors.centerIn: parent
        }
        Text{
            text: "6"
        }
    }

    NumberAnimation {
        id: a6x
        target: rectG6
        property: "x"
        duration: 500
        easing.type: Easing.OutBounce
        from: grect6.x
        to: grect6.to
        onStopped: {
            grect6.setX = grect6.to;
            //console.log("grect6: Reset X")
        }
    }
    Connections{
        target: grect6
        function onToChanged(){
            //console.log("Got start X animation grect6");
            a6x.from = grect6.x
            a6x.to =  grect6.to;
            a6x.restart();
        }
    }

    NumberAnimation {
        id: a6y
        target: rectG6
        property: "y"
        duration: 500
        easing.type: Easing.OutBounce
        from: grect6.y
        to: grect6.toY
        onStopped: {
            grect6.setY = grect6.toY;
            //console.log("grect6: Reset Y")
        }
    }
    Connections{
        target: grect6
        function onToYChanged(){
            //console.log("Got start Y animation grect6");
            a6y.from = grect6.y
            a6y.to =  grect6.toY;
            a6y.restart();
        }
    }
    StaticRect{
        id: rectG7
        color: grect7.color
        visible: grect7.visible
        x: grect7.x
        y: grect7.y
        Text {
            id: textG7
            text: grect7.text
            font.pointSize: 24
            anchors.centerIn: parent
        }
        Text{
            text: "7"
        }
    }

    NumberAnimation {
        id: a7x
        target: rectG7
        property: "x"
        duration: 500
        easing.type: Easing.OutBounce
        from: grect7.x
        to: grect7.to
        onStopped: {
            grect7.setX = grect7.to;
            //console.log("grect7: Reset X")
        }
    }
    Connections{
        target: grect7
        function onToChanged(){
            //console.log("Got start X animation grect7");
            a7x.from = grect7.x
            a7x.to =  grect7.to;
            a7x.restart();
        }
    }

    NumberAnimation {
        id: a7y
        target: rectG7
        property: "y"
        duration: 500
        easing.type: Easing.OutBounce
        from: grect7.y
        to: grect7.toY
        onStopped: {
            grect7.setY = grect7.toY;
            //console.log("grect7: Reset Y")
        }
    }
    Connections{
        target: grect7
        function onToYChanged(){
            //console.log("Got start Y animation grect7");
            a7y.from = grect7.y
            a7y.to =  grect7.toY;
            a7y.restart();
        }
    }

    StaticRect{
        id: rectG8
        color: grect8.color
        visible: grect8.visible
        x: grect8.x
        y: grect8.y
        Text {
            id: textG8
            text: grect8.text
            font.pointSize: 24
            anchors.centerIn: parent
        }
        Text{
            text: "8"
        }
    }

    NumberAnimation {
        id: a8x
        target: rectG8
        property: "x"
        duration: 500
        easing.type: Easing.OutBounce
        from: grect8.x
        to: grect8.to
        onStopped: {
            grect8.setX = grect8.to;
            //console.log("grect8: Reset X")
        }
    }
    Connections{
        target: grect8
        function onToChanged(){
            console.log("Got start X animation grect8");
            a8x.from = grect8.x
            a8x.to =  grect8.to;
            a8x.restart();
        }
    }

    NumberAnimation {
        id: a8y
        target: rectG8
        property: "y"
        duration: 500
        easing.type: Easing.OutBounce
        from: grect8.y
        to: grect8.toY
        onStopped: {
            grect8.setY = grect8.toY;
            //console.log("grect8: Reset Y")
        }
    }
    Connections{
        target: grect8
        function onToYChanged(){
            //console.log("Got start Y animation grect8");
            a8y.from = grect8.y
            a8y.to =  grect8.toY;
            a8y.restart();
        }
    }
    StaticRect{
        id: rectG9
        color: grect9.color
        visible: grect9.visible
        x: grect9.x
        y: grect9.y
        Text {
            id: textG9
            text: grect9.text
            font.pointSize: 24
            anchors.centerIn: parent
        }
        Text{
            text: "9"
        }
    }

    NumberAnimation {
        id: a9x
        target: rectG9
        property: "x"
        duration: 500
        easing.type: Easing.OutBounce
        from: grect9.x
        to: grect9.to
        onStopped: {
            grect9.setX = grect9.to;
            //console.log("grect9: Reset X")
        }
    }
    Connections{
        target: grect9
        function onToChanged(){
            ///console.log("Got start X animation grect9");
            a9x.from = grect9.x
            a9x.to =  grect9.to;
            a9x.restart();
        }
    }

    NumberAnimation {
        id: a9y
        target: rectG9
        property: "y"
        duration: 500
        easing.type: Easing.OutBounce
        from: grect9.y
        to: grect9.toY
        onStopped: {
            grect9.setY = grect9.toY;
            //console.log("grect9: Reset Y")
        }
    }
    Connections{
        target: grect9
        function onToYChanged(){
            //console.log("Got start Y animation grect9");
            a9y.from = grect9.y
            a9y.to =  grect9.toY;
            a9y.restart();
        }
    }
    StaticRect{
        id: rectG10
        color: grect10.color
        visible: grect10.visible
        x: grect10.x
        y: grect10.y
        Text {
            id: textG10
            text: grect10.text
            font.pointSize: 24
            anchors.centerIn: parent
        }
        Text{
            text: "10"
        }
    }

    NumberAnimation {
        id: a10x
        target: rectG10
        property: "x"
        duration: 500
        easing.type: Easing.OutBounce
        from: grect10.x
        to: grect10.to
        onStopped: {
            grect10.setX = grect10.to;
            //console.log("grect10: Reset X")
        }
    }
    Connections{
        target: grect10
        function onToChanged(){
            //console.log("Got start X animation grect10");
            a10x.from = grect10.x
            a10x.to =  grect10.to;
            a10x.restart();
        }
    }

    NumberAnimation {
        id: a10y
        target: rectG10
        property: "y"
        duration: 500
        easing.type: Easing.OutBounce
        from: grect10.y
        to: grect10.toY
        onStopped: {
            grect10.setY = grect10.toY;
            //console.log("grect10: Reset Y")
        }
    }
    Connections{
        target: grect10
        function onToYChanged(){
            //console.log("Got start Y animation grect10");
            a10y.from = grect10.y
            a10y.to =  grect10.toY;
            a10y.restart();
        }
    }
    StaticRect{
        id: rectG11
        color: grect11.color
        visible: grect11.visible
        x: grect11.x
        y: grect11.y
        Text {
            id: textG11
            text: grect11.text
            font.pointSize: 24
            anchors.centerIn: parent
        }
        Text{
            text: "11"
        }
    }

    NumberAnimation {
        id: a11x
        target: rectG11
        property: "x"
        duration: 500
        easing.type: Easing.OutBounce
        from: grect11.x
        to: grect11.to
        onStopped: {
            grect11.setX = grect11.to;
            //console.log("grect11: Reset X")
        }
    }
    Connections{
        target: grect11
        function onToChanged(){
            //console.log("Got start X animation grect11");
            a11x.from = grect11.x
            a11x.to =  grect11.to;
            a11x.restart();
        }
    }

    NumberAnimation {
        id: a11y
        target: rectG11
        property: "y"
        duration: 500
        easing.type: Easing.OutBounce
        from: grect11.y
        to: grect11.toY
        onStopped: {
            grect11.setY = grect11.toY;
            //console.log("grect11: Reset Y")
        }
    }
    Connections{
        target: grect11
        function onToYChanged(){
            //console.log("Got start Y animation grect11");
            a11y.from = grect11.y
            a11y.to =  grect11.toY;
            a11y.restart();
        }
    }

    StaticRect{
        id: rectG12
        color: grect12.color
        visible: grect12.visible
        x: grect12.x
        y: grect12.y
        Text {
            id: textG12
            text: grect12.text
            font.pointSize: 24
            anchors.centerIn: parent
        }
        Text{
            text: "12"
        }
    }

    NumberAnimation {
        id: a12x
        target: rectG12
        property: "x"
        duration: 500
        easing.type: Easing.OutBounce
        from: grect12.x
        to: grect12.to
        onStopped: {
            grect12.setX = grect12.to;
            //console.log("grect12: Reset X")
        }
    }
    Connections{
        target: grect12
        function onToChanged(){
            //console.log("Got start X animation grect12");
            a12x.from = grect12.x
            a12x.to =  grect12.to;
            a12x.restart();
        }
    }

    NumberAnimation {
        id: a12y
        target: rectG12
        property: "y"
        duration: 500
        easing.type: Easing.OutBounce
        from: grect12.y
        to: grect12.toY
        onStopped: {
            grect12.setY = grect12.toY;
            //console.log("grect12: Reset Y")
        }
    }
    Connections{
        target: grect12
        function onToYChanged(){
            //console.log("Got start Y animation grect12");
            a12y.from = grect12.y
            a12y.to =  grect12.toY;
            a12y.restart();
        }
    }

    StaticRect{
        id: rectG13
        color: grect13.color
        visible: grect13.visible
        x: grect13.x
        y: grect13.y
        Text {
            id: textG13
            text: grect13.text
            font.pointSize: 24
            anchors.centerIn: parent
        }
        Text{
            text: "13"
        }
    }

    NumberAnimation {
        id: a13x
        target: rectG13
        property: "x"
        duration: 500
        easing.type: Easing.OutBounce
        from: grect13.x
        to: grect13.to
        onStopped: {
            grect13.setX = grect13.to;
            //console.log("grect13: Reset X")
        }
    }
    Connections{
        target: grect13
        function onToChanged(){
            //console.log("Got start X animation grect13");
            a13x.from = grect13.x
            a13x.to =  grect13.to;
            a13x.restart();
        }
    }

    NumberAnimation {
        id: a13y
        target: rectG13
        property: "y"
        duration: 500
        easing.type: Easing.OutBounce
        from: grect13.y
        to: grect13.toY
        onStopped: {
            grect13.setY = grect13.toY;
            console.log("grect13: Reset Y")
        }
    }
    Connections{
        target: grect13
        function onToYChanged(){
            //console.log("Got start Y animation grect13");
            a13y.from = grect13.y
            a13y.to =  grect13.toY;
            a13y.restart();
        }
    }

    StaticRect{
        id: rectG14
        color: grect14.color
        visible: grect14.visible
        x: grect14.x
        y: grect14.y
        Text {
            id: textG14
            text: grect14.text
            font.pointSize: 24
            anchors.centerIn: parent
        }
        Text{
            text: "14"
        }
    }

    NumberAnimation {
        id: a14x
        target: rectG14
        property: "x"
        duration: 500
        easing.type: Easing.OutBounce
        from: grect14.x
        to: grect14.to
        onStopped: {
            grect14.setX = grect14.to;
            //console.log("grect14: Reset X")
        }
    }
    Connections{
        target: grect14
        function onToChanged(){
            //console.log("Got start X animation grect14");
            a14x.from = grect14.x
            a14x.to =  grect14.to;
            a14x.restart();
        }
    }

    NumberAnimation {
        id: a14y
        target: rectG14
        property: "y"
        duration: 500
        easing.type: Easing.OutBounce
        from: grect14.y
        to: grect14.toY
        onStopped: {
            grect14.setY = grect14.toY;
            //console.log("grect14: Reset Y")
        }
    }
    Connections{
        target: grect14
        function onToYChanged(){
            //console.log("Got start Y animation grect14");
            a14y.from = grect14.y
            a14y.to = grect14.toY;
            a14y.restart();
        }
    }

    StaticRect{
        id: rectG15
        color: grect15.color
        visible: grect15.visible
        x: grect15.x
        y: grect15.y
        Text {
            id: textG15
            text: grect15.text
            font.pointSize: 24
            anchors.centerIn: parent
        }
        Text{
            text: "15"
        }
    }

    NumberAnimation {
        id: a15x
        target: rectG15
        property: "x"
        duration: 500
        easing.type: Easing.OutBounce
        from: grect15.x
        to: grect15.to
        onStopped: {
            grect15.setX = grect15.to;
            //console.log("grect15: Reset X")
        }
    }
    Connections{
        target: grect15
        function onToChanged(){
            //console.log("Got start X animation grect15");
            a15x.from = grect15.x
            a15x.to =  grect15.to;
            a15x.restart();
        }
    }

    NumberAnimation {
        id: a15y
        target: rectG15
        property: "y"
        duration: 500
        easing.type: Easing.OutBounce
        from: grect15.y
        to: grect15.toY
        onStopped: {
            grect15.setY = grect15.toY;
            //console.log("grect1: Reset Y")
        }
    }
    Connections{
        target: grect15
        function onToYChanged(){
            //console.log("Got start Y animation grect15");
            a15y.from = grect15.y
            a15y.to =  grect15.toY;
            a15y.restart();
        }
    }


    Dialog{
        id: rulesDialog
        modality: Qt.ApplicationModal
        standardButtons: Dialog.Close
        width: Math.min(rootId.width, rootId.height) / 3 * 2
        height: rootId.height / 2
        title: "Правила"

        Flickable{
            id: flicableId
            clip: true
            anchors.fill: parent
            contentHeight: columnId.implicitHeight
            ScrollBar.vertical: ScrollBar{}

            Column{
                id: columnId
                spacing: 20
                anchors.fill: parent
                Label{
                    width: parent.width
                    text: "В каждом раунде появляется плитка номинала «2» (с вероятностью 90 %) или «4» (с вероятностью 10 %)"
                          + " Нажатием стрелки игрок может скинуть все плитки игрового поля в одну из 4 сторон. Если при сбрасывании две плитки одного номинала «налетают» одна на другую, то они превращаются в одну, номинал которой равен сумме соединившихся плиток. После каждого хода на свободной секции поля появляется новая плитка номиналом «2» или «4». Если при нажатии кнопки местоположение плиток или их номинал не изменится, то ход не совершается."
                          + " Если в одной строчке или в одном столбце находится более двух плиток одного номинала, то при сбрасывании они начинают соединяться с той стороны, в которую были направлены. Например, находящиеся в одной строке плитки (4, 4, 4) после хода влево превратятся в (8, 4), а после хода вправо — в (4, 8). Данная обработка неоднозначности позволяет более точно формировать стратегию игры."
                          + " За каждое соединение игровые очки увеличиваются на номинал получившейся плитки."
                          + " Игра заканчивается поражением, если после очередного хода невозможно совершить действие."
                    wrapMode: Label.Wrap
                }

            }

        }

    }

    Dialog{
        id: endGameDialog
        title: "Игра окончена!"
        modality: Qt.ApplicationModal
        standardButtons: Dialog.Close
        width: Math.min(rootId.width, rootId.height) / 3 * 2
        height: rootId.height / 4
        Label{
            id: endGameDialogLabel
            width: parent.width
            text: "Вы проиграли! Попробуйте еще раз"
            wrapMode: Label.Wrap
        }
    }

    Connections{
        target: scorecounter
        function onEndGameTextChanged(){
            endGameDialogLabel.text = scorecounter.endGameText
            endGameDialog.open();
        }
    }
}
