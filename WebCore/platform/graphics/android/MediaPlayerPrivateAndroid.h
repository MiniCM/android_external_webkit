/*
 * Copyright 2009, The Android Open Source Project
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 *  * Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 *  * Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS ``AS IS'' AND ANY
 * EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR
 * PURPOSE ARE DISCLAIMED.  IN NO EVENT SHALL APPLE COMPUTER, INC. OR
 * CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL,
 * EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,
 * PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR
 * PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY
 * OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
 * OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

#ifndef MediaPlayerPrivateAndroid_h
#define MediaPlayerPrivateAndroid_h

#if ENABLE(VIDEO)

#include "MediaPlayerPrivate.h"

namespace WebCore {

class MediaPlayerPrivate : public MediaPlayerPrivateInterface {
public:
    static void registerMediaEngine(MediaEngineRegistrar);

    virtual void load(const String& url);
    virtual void cancelLoad();

    virtual void play();
    virtual void pause();

    virtual IntSize naturalSize() const;

    virtual bool hasVideo() const;

    virtual void setVisible(bool);

    virtual float duration() const;

    virtual float currentTime() const;
    virtual void seek(float time);
    virtual bool seeking() const;

    virtual void setEndTime(float time);

    virtual void setRate(float);
    virtual bool paused() const;

    virtual void setVolume(float);

    virtual MediaPlayer::NetworkState networkState() const;
    virtual MediaPlayer::ReadyState readyState() const;

    virtual float maxTimeSeekable() const;
    virtual float maxTimeBuffered() const;

    virtual int dataRate() const;

    virtual bool totalBytesKnown() const { return totalBytes() > 0; }
    virtual unsigned totalBytes() const;
    virtual unsigned bytesLoaded() const;

    virtual void setSize(const IntSize&);

    virtual void paint(GraphicsContext*, const IntRect&);
private:
    static MediaPlayerPrivateInterface* create(MediaPlayer* player);
    static void getSupportedTypes(HashSet<String>&);
    static MediaPlayer::SupportsType supportsType(const String& type, const String& codecs);
};

}  // namespace WebCore

#endif

#endif // MediaPlayerPrivateAndroid_h