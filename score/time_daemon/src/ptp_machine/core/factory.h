/********************************************************************************
 * Copyright (c) 2026 Contributors to the Eclipse Foundation
 *
 * See the NOTICE file(s) distributed with this work for additional
 * information regarding copyright ownership.
 *
 * This program and the accompanying materials are made available under the
 * terms of the Apache License Version 2.0 which is available at
 * https://www.apache.org/licenses/LICENSE-2.0
 *
 * SPDX-License-Identifier: Apache-2.0
 ********************************************************************************/
#ifndef SCORE_TIME_DAEMON_SRC_PTP_MACHINE_CORE_FACTORY_H
#define SCORE_TIME_DAEMON_SRC_PTP_MACHINE_CORE_FACTORY_H

#include "score/time_daemon/src/ptp_machine/core/ptp_machine.h"

#include <chrono>
#include <memory>
#include <string>
#include <utility>

namespace score
{
namespace td
{

/**
 * @brief Factory function to create a PTPMachine that reads its PTP engine every 50 ms.
 *
 * @tparam PTPEngine Engine that reads the data from the PTP stack, see PTPMachine for its requirements.
 * @param name Logical name for the machine instance.
 * @param args Arguments forwarded to the PTPEngine constructor.
 * @return A fully configured PTPMachine instance.
 */
template <class PTPEngine, typename... PTPEngineArgs>
std::shared_ptr<PTPMachine<PTPEngine>> CreatePTPMachine(const std::string& name, PTPEngineArgs&&... args)
{
    constexpr std::chrono::milliseconds updateInterval(50);
    return std::make_shared<PTPMachine<PTPEngine>>(name, updateInterval, std::forward<PTPEngineArgs>(args)...);
}

}  // namespace td
}  // namespace score

#endif  // SCORE_TIME_DAEMON_SRC_PTP_MACHINE_CORE_FACTORY_H
