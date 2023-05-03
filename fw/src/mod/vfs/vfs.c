#include "vfs.h"

// #define VFS_LFS_ENABLE

#ifdef VFS_LFS_ENABLE
    #include "vfs_driver_lfs.h"
    #define VFS_DRIVER {.enabled = true, .p_driver = &vfs_driver_lfs}
#else
    #include "vfs_driver_spiffs.h"
    #define VFS_DRIVER {.enabled = true, .p_driver = &vfs_driver_spiffs}
#endif

typedef struct {
    bool enabled;
    vfs_driver_t *p_driver;
} vfs_drive_item_t;

static vfs_drive_item_t vfs_drive_items[VFS_DRIVE_MAX] = {
    [VFS_DRIVE_INT] =
        {
            .enabled = false,
            .p_driver = NULL,
        },
    [VFS_DRIVE_EXT] = VFS_DRIVER
};


bool vfs_drive_enabled(vfs_drive_t drive) { return vfs_drive_items[drive].enabled; }

vfs_driver_t *vfs_get_driver(vfs_drive_t drive) { return vfs_drive_items[drive].p_driver; }