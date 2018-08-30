//
// Created by joaquin on 30/08/18.
//
//
//void getHands(const Leap::Frame frame){
//    HandList hands = frame.hands();
//    for (HandList::const_iterator hl = hands.begin(); hl != hands.end(); ++hl) {
//        // Get the first hand
//        const Hand hand = *hl;
//        std::string handType = hand.isLeft() ? "Left hand" : "Right hand";
//        std::cout << std::string(2, ' ') << handType << ", id: " << hand.id()
//                  << ", palm position: " << hand.palmPosition() << std::endl;
//        // Get the hand's normal vector and direction
//        const Vector normal = hand.palmNormal();
//        const Vector direction = hand.direction();
//
//        // Calculate the hand's pitch, roll, and yaw angles
//        std::cout << std::string(2, ' ') <<  "pitch: " << direction.pitch() * RAD_TO_DEG << " degrees, "
//                  << "roll: " << normal.roll() * RAD_TO_DEG << " degrees, "
//                  << "yaw: " << direction.yaw() * RAD_TO_DEG << " degrees" << std::endl;
//
//        // Get the Arm bone
//        Arm arm = hand.arm();
//        std::cout << std::string(2, ' ') <<  "Arm direction: " << arm.direction()
//                  << " wrist position: " << arm.wristPosition()
//                  << " elbow position: " << arm.elbowPosition() << std::endl;
//
//        // Get fingers
//        const FingerList fingers = hand.fingers();
//        for (FingerList::const_iterator fl = fingers.begin(); fl != fingers.end(); ++fl) {
//            const Finger finger = *fl;
//            std::cout << std::string(4, ' ') <<  fingerNames[finger.type()]
//                      << " finger, id: " << finger.id()
//                      << ", length: " << finger.length()
//                      << "mm, width: " << finger.width() << std::endl;
//
//            // Get finger bones
//            for (int b = 0; b < 4; ++b) {
//                Bone::Type boneType = static_cast<Bone::Type>(b);
//                Bone bone = finger.bone(boneType);
//                std::cout << std::string(6, ' ') <<  boneNames[boneType]
//                          << " bone, start: " << bone.prevJoint()
//                          << ", end: " << bone.nextJoint()
//                          << ", direction: " << bone.direction() << std::endl;
//            }
//        }
//    }
//}




//    std::cout << "Frame id: " << frame.id()
//              << ", timestamp: " << frame.timestamp()
//              << ", hands: " << frame.hands().count()
//              << ", extended fingers: " << frame.fingers().extended().count()
//              << ", tools: " << frame.tools().count()
//              << ", gestures: " << frame.gestures().count() << std::endl;
//    getHands(frame);
//    getGestures(frame,controller);