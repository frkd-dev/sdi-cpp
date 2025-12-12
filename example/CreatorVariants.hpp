#pragma once

// An enum of creator variants.
// NOTES:
// 1. The order isn't important.
// 2. This file should be a single one per project.

enum class Variant : uint8_t
{
    VideoPlayer,
    ImageViewer,
    AudioPlayer,
    Window
};
