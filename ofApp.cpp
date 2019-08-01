#include "ofApp.h"	

//--------------------------------------------------------------
void ofApp::setup() {

	ofSetFrameRate(60);
	ofSetWindowTitle("openFrameworks");

	ofBackground(239);
	ofNoFill();
	ofSetLineWidth(3);
}

//--------------------------------------------------------------
void ofApp::update() {

	ofSeedRandom(39);
}

//--------------------------------------------------------------
void ofApp::draw() {

	this->cam.begin();
	ofRotateY(ofGetFrameNum() * 0.8);

	auto len = 300;
	for (int i = 0; i < 6; i++) {

		if (i < 4) {
		
			ofRotateX(90);
		}
		else if (i < 5) {

			ofRotateY(90);
		}
		else {

			ofRotateY(180);
		}

		for (int k = 0; k < 8; k++) {

			auto location = glm::vec3(ofRandom(-len * 0.5, len * 0.5), ofRandom(-len * 0.5, len * 0.5), len * 0.5);
			auto radius = (int)(ofRandom(100) + ofGetFrameNum()) % 100;

			auto alpha = 255;
			if (radius > 50) {

				alpha = ofMap(radius, 50, 100, 255, 0);
			}

			ofSetColor(39, alpha);

			ofBeginShape();
			for (int deg = 0; deg < 360; deg++) {

				auto point = location + glm::vec2(radius * cos(deg * DEG_TO_RAD), radius * sin(deg * DEG_TO_RAD));

				if (point.y > len * 0.5) { point.y = len * 0.5; }
				if (point.y < -len * 0.5) { point.y = -len * 0.5; }
				if (point.x > len * 0.5) { point.x = len * 0.5; }
				if (point.x < -len * 0.5) { point.x = -len * 0.5; }

				ofVertex(point);
			}
			ofEndShape(true);
		}
	}

	this->cam.end();
}

//--------------------------------------------------------------
int main() {

	ofSetupOpenGL(720, 720, OF_WINDOW);
	ofRunApp(new ofApp());
}