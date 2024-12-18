//
//  Treeeeee.c
//  Treeeeee
//
//  Created by Shoumik Daterao on 16/10/24.
//

#include <mach/mach_types.h>

kern_return_t Treeeeee_start(kmod_info_t * ki, void *d);
kern_return_t Treeeeee_stop(kmod_info_t *ki, void *d);

kern_return_t Treeeeee_start(kmod_info_t * ki, void *d)
{
    return KERN_SUCCESS;
}

kern_return_t Treeeeee_stop(kmod_info_t *ki, void *d)
{
    return KERN_SUCCESS;
}
