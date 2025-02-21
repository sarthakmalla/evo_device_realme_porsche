/*
 * Copyright (C) 2022 The LineageOS Project
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *      http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#define LOG_TAG "android.hardware.biometrics.fingerprint@2.3-service.porsche"

#include <android-base/logging.h>
#include <hidl/HidlTransportSupport.h>

#include "BiometricsFingerprint.h"

using android::sp;
using android::hardware::configureRpcThreadpool;
using android::hardware::joinRpcThreadpool;
using android::hardware::biometrics::fingerprint::V2_3::IBiometricsFingerprint;
using android::hardware::biometrics::fingerprint::V2_3::implementation::BiometricsFingerprint;

int main() {
    sp<IBiometricsFingerprint> bio = new BiometricsFingerprint();

    configureRpcThreadpool(1, true /*callerWillJoin*/);

    if (bio->registerAsService() != android::OK) {
        LOG(ERROR) << "Can't register BiometricsFingerprint HAL service";
        return 1;
    }

    joinRpcThreadpool();

    return 0;  // should never get here
}
