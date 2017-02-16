#include "ofApp.h"


//--------------------------------------------------------------
void ofApp::setup(){
	
	kinect.initSensor();
	kinect.initDepthStream(640, 480, true);
	kinect.initSkeletonStream(true);

	kinect.start();
	ofDisableAlphaBlending(); //Kinect alpha channel is default 0;
	NuiCameraElevationSetAngle(15);//tilt angle
}

//--------------------------------------------------------------
void ofApp::update(){
	kinect.update();
}

//--------------------------------------------------------------
void ofApp::draw(){
	kinect.draw(640, 0);
	kinect.drawDepth(0, 0);

	auto skeletons = kinect.getSkeletons();
	cout <<"Skeleton size: "<<skeletons.size();
	cout << "\n";

	//ofPushStyle();
	//ofSetColor(255, 0, 0);
	//ofSetLineWidth(3.0f);
	//for (auto & skeleton : skeletons) {
	//	for (auto & bone : skeleton) {
	//		switch (bone.second.getTrackingState()) {
	//		case SkeletonBone::Inferred:
	//			ofSetColor(0, 0, 255);
	//			break;
	//		case SkeletonBone::Tracked:
	//			ofSetColor(0, 255, 0);
	//			break;
	//		case SkeletonBone::NotTracked:
	//			ofSetColor(255, 0, 0);
	//			break;
	//		}

	//		auto index = bone.second.getStartJoint();
	//		auto connectedTo = skeleton.find((_NUI_SKELETON_POSITION_INDEX)index);
	//		if (connectedTo != skeleton.end()) {
	//			ofLine(connectedTo->second.getScreenPosition(), bone.second.getScreenPosition());
	//		}

	//		ofCircle(bone.second.getScreenPosition(), 10.0f);
	//	}
	//}
	//ofPopStyle();

	for (auto & skeleton : skeletons) {//loop through all skeletons tracked 
		for (int i = 0; i < skeleton.size(); i++)// get skeleton bones 
		{

				SkeletonBone lHandBone = skeleton.find(NUI_SKELETON_POSITION_HAND_LEFT)->second;
				ofVec2f lhandScrenPosition(lHandBone.getScreenPosition().x, lHandBone.getScreenPosition().y);
				cout << "left hand position: " << lHandBone.getScreenPosition().x << " left hand position y: " << lHandBone.getScreenPosition().y;
				ofPushStyle();
				ofSetColor(0, 205, 80);
				ofDrawCircle(lHandBone.getScreenPosition().x, lHandBone.getScreenPosition().y, 10);
				ofPopStyle();

				cout << "\n";
				SkeletonBone RHandBone = skeleton.find(NUI_SKELETON_POSITION_HAND_RIGHT)->second;
				ofVec2f RhandScrenPosition(RHandBone.getScreenPosition().x, RHandBone.getScreenPosition().y);
				cout << "Right hand position: " << RHandBone.getScreenPosition().x << " Right hand position y: " << RHandBone.getScreenPosition().y;
				ofPushStyle();
				ofSetColor(5, 10, 105);
				ofFill();
				ofDrawCircle(RHandBone.getScreenPosition().x, RHandBone.getScreenPosition().y, 10);
				ofPopStyle();
		}
	}

}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}
