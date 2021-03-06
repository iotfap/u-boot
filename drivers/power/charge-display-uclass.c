/*
 * (C) Copyright 2017 Rockchip Electronics Co., Ltd
 *
 * SPDX-License-Identifier:     GPL-2.0+
 */

#include <command.h>
#include <common.h>
#include <dm.h>
#include <power/charge_display.h>

int charge_display_get_power_on_soc(struct udevice *dev)
{
	const struct dm_charge_display_ops *ops = dev_get_driver_ops(dev);

	if (!ops || !ops->get_power_on_soc)
		return -ENOSYS;

	return ops->get_power_on_soc(dev);
}

int charge_display_get_power_on_voltage(struct udevice *dev)
{
	const struct dm_charge_display_ops *ops = dev_get_driver_ops(dev);

	if (!ops || !ops->get_power_on_voltage)
		return -ENOSYS;

	return ops->get_power_on_voltage(dev);
}

int charge_display_show(struct udevice *dev)
{
	const struct dm_charge_display_ops *ops = dev_get_driver_ops(dev);

	if (!ops || !ops->show)
		return -ENOSYS;

	return ops->show(dev);
}

UCLASS_DRIVER(charge_display) = {
	.id	= UCLASS_CHARGE_DISPLAY,
	.name	= "charge_display",
};
