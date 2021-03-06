/*
 * Copyright (C) 2015 Jolla Ltd.
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
 *
 * Authored by: Juho Hämäläinen <juho.hamalainen@jolla.com>
 */

#ifndef DROID_IPRIVATE_AF_GLUE_HANDLER_H
#define DROID_IPRIVATE_AF_GLUE_HANDLER_H

#include <stdint.h>
#include <sys/types.h>
#include <unistd.h>

#include <utils/RefBase.h>
#include <binder/IInterface.h>
#include <binder/Parcel.h>
#include <media/AudioParameter.h>
#include <utils/String8.h>
#include <system/audio.h>

namespace android {

    class IPrivateAfGlueHandler : public IInterface
    {
    public:
        DECLARE_META_INTERFACE(PrivateAfGlueHandler);

        virtual status_t handleSetParameters(audio_io_handle_t ioHandle,
                                             const String8 &keyValuePairs) = 0;
        virtual String8 handleGetParameters(audio_io_handle_t ioHandle,
                                            const String8 &keys) const = 0;
    };

    class BnPrivateAfGlueHandler : public BnInterface<IPrivateAfGlueHandler>
    {
    public:
        virtual status_t    onTransact( uint32_t code,
                                        const Parcel& data,
                                        Parcel* reply,
                                        uint32_t flags = 0);
    };

};
#endif
