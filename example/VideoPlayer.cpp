#include <memory>
#include <functional>

#include <VideoPlayer.hpp>
#include <Creator.hpp>

// Make aliases to get readable code 
using SharedInstance  = std::shared_ptr<VideoPlayer>;
using InstanceCreator = Creator<SharedInstance, Variant::VideoPlayer>;

template <>
auto getCreator<SharedInstance, Variant::VideoPlayer>()
{
    return InstanceCreator([]() {
        return std::make_shared<VideoPlayerImpl>();
    });
}

// Since everything within a translation unit (a cpp file) is hidden from other translation units,
// we can use "public by default" structs instead of "private by default" classes.
// In otheer words, we have "private by implementation" approach rather than "private by declaration".
// This gives small benefits like ommiting public/private decrlations,
// which makes code a bit cleaner and easier to read.
struct VideoPlayerImpl : VideoPlayer {
    VideoPlayerImpl() = defult;
    override ~VideoPlayerImpl() final = default;

    override void play() final {
        // playing
    }
};
