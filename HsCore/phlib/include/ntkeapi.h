#ifndef _NTKEAPI_H
#define _NTKEAPI_H

#if (PHNT_MODE != PHNT_MODE_KERNEL)
#define LOW_PRIORITY 0 // Lowest thread priority level
#define LOW_REALTIME_PRIORITY 16 // Lowest realtime priority level
#define HIGH_PRIORITY 31 // Highest thread priority level
#define MAXIMUM_PRIORITY 32 // Number of thread priority levels
#endif

typedef enum _KTHREAD_STATE
{
    Initialized,
    Ready,
    Running,
    Standby,
    Terminated,
    Waiting,
    Transition,
    DeferredReady,
    GateWait,
    MaximumThreadState
} KTHREAD_STATE, *PKTHREAD_STATE;

#if (PHNT_MODE != PHNT_MODE_KERNEL)

typedef enum _KWAIT_REASON
{
    Executive,
    FreePage,
    PageIn,
    PoolAllocation,
    DelayExecution,
    Suspended,
    UserRequest,
    WrExecutive,
    WrFreePage,
    WrPageIn,
    WrPoolAllocation,
    WrDelayExecution,
    WrSuspended,
    WrUserRequest,
    WrEventPair,
    WrQueue,
    WrLpcReceive,
    WrLpcReply,
    WrVirtualMemory,
    WrPageOut,
    WrRendezvous,
    WrKeyedEvent,
    WrTerminated,
    WrProcessInSwap,
    WrCpuRateControl,
    WrCalloutStack,
    WrKernel,
    WrResource,
    WrPushLock,
    WrMutex,
    WrQuantumEnd,
    WrDispatchInt,
    WrPreempted,
    WrYieldExecution,
    WrFastMutex,
    WrGuardedMutex,
    WrRundown,
    WrAlertByThreadId,
    WrDeferredPreempt,
    MaximumWaitReason
} KWAIT_REASON, *PKWAIT_REASON;

typedef enum _KPROFILE_SOURCE
{
    ProfileTime,
    ProfileAlignmentFixup,
    ProfileTotalIssues,
    ProfilePipelineDry,
    ProfileLoadInstructions,
    ProfilePipelineFrozen,
    ProfileBranchInstructions,
    ProfileTotalNonissues,
    ProfileDcacheMisses,
    ProfileIcacheMisses,
    ProfileCacheMisses,
    ProfileBranchMispredictions,
    ProfileStoreInstructions,
    ProfileFpInstructions,
    ProfileIntegerInstructions,
    Profile2Issue,
    Profile3Issue,
    Profile4Issue,
    ProfileSpecialInstructions,
    ProfileTotalCycles,
    ProfileIcacheIssues,
    ProfileDcacheAccesses,
    ProfileMemoryBarrierCycles,
    ProfileLoadLinkedIssues,
    ProfileMaximum
} KPROFILE_SOURCE;

#endif

#if (PHNT_MODE != PHNT_MODE_KERNEL)

NTSYSCALLAPI
NTSTATUS
NTAPI
NtCallbackReturn(
    _In_reads_bytes_opt_(OutputLength) PVOID OutputBuffer,
    _In_ ULONG OutputLength,
    _In_ NTSTATUS Status
    );

NTSYSCALLAPI
NTSTATUS
NTAPI
NtQueryDebugFilterState(
    _In_ ULONG ComponentId,
    _In_ ULONG Level
    );

NTSYSCALLAPI
NTSTATUS
NTAPI
NtSetDebugFilterState(
    _In_ ULONG ComponentId,
    _In_ ULONG Level,
    _In_ BOOLEAN State
    );

NTSYSCALLAPI
NTSTATUS
NTAPI
NtYieldExecution(
    VOID
    );

#if (PHNT_VERSION >= PHNT_VISTA)
// winnt:FlushProcessWriteBuffers
NTSYSCALLAPI
VOID
NTAPI
NtFlushProcessWriteBuffers(
    VOID
    );
#endif

#endif

#endif
