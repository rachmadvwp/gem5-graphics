/*
 * Copyright (c) 2018 University of British Columbia
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are
 * met: redistributions of source code must retain the above copyright
 * notice, this list of conditions and the following disclaimer;
 * redistributions in binary form must reproduce the above copyright
 * notice, this list of conditions and the following disclaimer in the
 * documentation and/or other materials provided with the distribution;
 * neither the name of the copyright holders nor the names of its
 * contributors may be used to endorse or promote products derived from
 * this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
 * "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
 * LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
 * A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
 * OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
 * SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
 * LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
 * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
 * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
 * OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 *
 * Authors: Ayub A. Gubran
 */

#include "graphics/gpu_standalone.hh"

#include "base/misc.hh"
#include "base/statistics.hh"
#include "debug/GPUStandalone.hh"
#include "sim/sim_events.hh"
#include "sim/stats.hh"
#include "sim/system.hh"


GPUStandalone::GPUStandalone(const Params *p) :
      ClockedObject(p),
      tickEvent(this),
      traceStarted(false),
      traceDone(false)
{
   schedule(tickEvent, 0);
}

void
GPUStandalone::init()
{
}

void
GPUStandalone::tick()
{
   if(not traceStarted){
      //start api trace
      printf("starting trace\n");
      traceStarted = true;
      return;
   }

   if(traceDone){
      panic("need to check gpu has no work left");
      exitSimLoop("Done with trace\n");
   } else {
      //check later
      schedule(tickEvent, 10000);
   }
}


GPUStandalone *GPUStandaloneParams::create() {
   return new GPUStandalone(this);
}
