/*-
 * Copyright (C) 2012 Margarida Gouveia
 * Copyright (C) 2024 Stefanos Stefanidis.
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 *
 * THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR
 * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES
 * OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.
 * IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT, INDIRECT,
 * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING,
 * BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
 * LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED
 * AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,
 * OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY
 * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF
 * SUCH DAMAGE.
 */
#include <sys/cdefs.h>
__FBSDID("$FreeBSD$");

#include <sys/param.h>
#include <sys/systm.h>
#include <sys/module.h>
#include <sys/bus.h>
#include <sys/conf.h>
#include <sys/kernel.h>
#include <sys/malloc.h>
#include <sys/rman.h>

#include <machine/bus.h>
#include <machine/platform.h>
#include <machine/intr_machdep.h>
#include <machine/resource.h>

#include <powerpc/wii/wii_ipcreg.h>

/*
 * Driver to interface with the Wii's IOS.
 *
 * IOS are small "microkernels" that run on the ARM9 core inside the
 * Broadway GPU and provide access to system services like USB.
 */
static int	wiiipc_probe(device_t);
static int	wiiipc_attach(device_t);

struct wiiipc_softc {
};

static device_method_t wiiipc_methods[] = {
	/* Device interface */
	DEVMETHOD(device_probe,		wiiipc_probe),
	DEVMETHOD(device_attach,	wiiipc_attach),

	DEVMETHOD_END
};

static driver_t wiiipc_driver = {
	"wiiipc",
	wiiipc_methods,
	sizeof(struct wiiipc_softc)
};

DRIVER_MODULE(wiiipc, wiibus, wiiipc_driver, NULL, NULL);

static int
wiiipc_probe(device_t dev)
{
        device_set_desc(dev, "Nintendo Wii IOS IPC");

        return (BUS_PROBE_NOWILDCARD);
}

/*
 * TODO: Finish this code.
 * For now, it does nothing.
 */
static int
wiiipc_attach(device_t dev)
{
	return (0);
}
