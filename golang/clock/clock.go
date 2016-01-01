package main

import (
	"fmt"
	"github.com/stianeikeland/go-rpio"
	"os"
	"time"
)

const (
	lightOne = iota
	lightTwo
	lightThree
	lightFour
	lightFive
	lightSix
)

const (
	ledAInBCM = rpio.Pin(2)
	ledBInBCM = rpio.Pin(3)
	ledCInBCM = rpio.Pin(4)
	ledDInBCM = rpio.Pin(17)
	ledEInBCM = rpio.Pin(27)
	ledFInBCM = rpio.Pin(22)
	ledGInBCM = rpio.Pin(10)
	ledDFInBCM = rpio.Pin(9)
)

const (
	numOneInBCM = rpio.Pin(14)
	numTwoInBCM = rpio.Pin(15)
	numThreeInBCM = rpio.Pin(18)
	numFourInBCM = rpio.Pin(23)
	numFiveInBCM = rpio.Pin(24)
	numSixInBCM = rpio.Pin(25)
)


var (
	arrayLight = []rpio.Pin {numOneInBCM, numTwoInBCM, numThreeInBCM, numFourInBCM, numFiveInBCM, numSixInBCM}
	arrayLed = []rpio.Pin {ledAInBCM, ledBInBCM, ledCInBCM, ledDInBCM, ledEInBCM, ledFInBCM, ledGInBCM, ledDFInBCM}
	hour, min, sec int
	currentLight int = -1;
	currentNum int = 0;

)

func main() {
	ticker := time.NewTicker(time.Millisecond * 2)
	go func() {
		if err := rpio.Open(); err != nil {
			fmt.Println(err)
			os.Exit(1)
		}

		defer rpio.Close()

		for _, pin := range arrayLight{
			pin.Output()
		}

		for _, pin := range arrayLed{
			pin.Output()
		}

		for t := range ticker.C {
			fmt.Println("Currnt time is ", t)
			hour, min, sec = t.Clock()
			currentLight = (currentLight + 1) % 6
			switch currentLight {
			case lightOne:
				currentNum = hour / 10
			case lightTwo:
				currentNum = hour % 10
			case lightThree:
				currentNum = min / 10
			case lightFour:
				currentNum = min % 10
			case lightFive:
				currentNum = sec / 10
			case lightSix:
				currentNum = sec % 10
			}
			lightNumber(currentLight, currentNum)
		}
	}()
}

func lightNumber(light int, number int) {
	for _, pin := range arrayLight{
		pin.Low()
	}
	ledDFInBCM.High()
	switch number {
	case 0:
		ledAInBCM.Low()
		ledBInBCM.Low()
		ledCInBCM.Low()
		ledDInBCM.Low()
		ledEInBCM.Low()
		ledFInBCM.Low()
		ledGInBCM.High()
	case 1:
		ledAInBCM.High()
		ledBInBCM.Low()
		ledCInBCM.Low()
		ledDInBCM.High()
		ledEInBCM.High()
		ledFInBCM.High()
		ledGInBCM.High()
	case 2:
		ledAInBCM.Low()
		ledBInBCM.Low()
		ledCInBCM.High()
		ledDInBCM.Low()
		ledEInBCM.Low()
		ledFInBCM.High()
		ledGInBCM.Low()
	case 3:
		ledAInBCM.Low()
		ledBInBCM.Low()
		ledCInBCM.Low()
		ledDInBCM.Low()
		ledEInBCM.High()
		ledFInBCM.High()
		ledGInBCM.Low()
	case 4:
		ledAInBCM.High()
		ledBInBCM.Low()
		ledCInBCM.Low()
		ledDInBCM.High()
		ledEInBCM.High()
		ledFInBCM.Low()
		ledGInBCM.Low()
	case 5:
		ledAInBCM.Low()
		ledBInBCM.High()
		ledCInBCM.Low()
		ledDInBCM.Low()
		ledEInBCM.Low()
		ledFInBCM.Low()
		ledGInBCM.Low()
	case 6:
		ledAInBCM.Low()
		ledBInBCM.High()
		ledCInBCM.Low()
		ledDInBCM.Low()
		ledEInBCM.Low()
		ledFInBCM.Low()
		ledGInBCM.Low()
	case 7:
		ledAInBCM.Low()
		ledBInBCM.Low()
		ledCInBCM.Low()
		ledDInBCM.High()
		ledEInBCM.High()
		ledFInBCM.High()
		ledGInBCM.High()
	case 8:
		ledAInBCM.Low()
		ledBInBCM.Low()
		ledCInBCM.Low()
		ledDInBCM.Low()
		ledEInBCM.Low()
		ledFInBCM.Low()
		ledGInBCM.Low()
	case 9:
		ledAInBCM.Low()
		ledBInBCM.Low()
		ledCInBCM.Low()
		ledDInBCM.Low()
		ledEInBCM.High()
		ledFInBCM.Low()
		ledGInBCM.Low()
	}
	if light == lightFour {
		ledDFInBCM.Low()
	}
	arrayLight[light].High()
}

