#pragma once


/*
 * PDB file: \Nt-Crucial-Modules\Ntoskrnl\6.2.9200.17581\
 * Dumped by pdbex tool v0.4, by wbenny
 */


namespace wdk::build_9200
{

    enum : UINT32
    {
        NumberOfProcessor32 = 1,
        NumberOfProcessor64 = 20,

        NumberOfProcessor = (sizeof(PVOID) == sizeof(UINT32)) ? NumberOfProcessor32 : NumberOfProcessor64,
    };

    typedef struct _KAFFINITY_EX
    {
        UINT16 Count;
        UINT16 Size;
        UINT32 Reserved;
        SIZE_T Bitmap[NumberOfProcessor];
    } KAFFINITY_EX, *PKAFFINITY_EX;
    static_assert(sizeof(KAFFINITY_EX) == (sizeof(SIZE_T) == sizeof(UINT64) ? 0xA8 : 0xC));

    
    typedef struct _KPROCESS
    {
        struct _DISPATCHER_HEADER Header;
        struct _LIST_ENTRY ProfileListHead;
        SIZE_T DirectoryTableBase;
#ifdef _X86_
        struct _KGDTENTRY LdtDescriptor;
        struct _KIDTENTRY Int21Descriptor;
#endif
        struct _LIST_ENTRY ThreadListHead;
        UINT32 ProcessLock;
#ifdef _WIN64
        UINT32 Spare0;
#endif
        struct _KAFFINITY_EX Affinity;
        struct _LIST_ENTRY ReadyListHead;
        struct _SINGLE_LIST_ENTRY SwapListEntry;
        volatile struct _KAFFINITY_EX ActiveProcessors;
        union
        {
            struct /* bitfield */
            {
                INT32 AutoAlignment : 1; /* bit position: 0 */
                INT32 DisableBoost : 1; /* bit position: 1 */
                INT32 DisableQuantum : 1; /* bit position: 2 */
                INT32 AffinitySet : 1; /* bit position: 3 */
                UINT32 DeepFreeze : 1; /* bit position: 4 */
                UINT32 TimerVirtualization : 1; /* bit position: 5 */
                UINT32 ActiveGroupsMask : NumberOfProcessor; /* bit position: 6 */
                INT32 ReservedFlags : (sizeof(UINT32) * 8) - 6 - NumberOfProcessor; /* bit position: 26 */ /* bit position: 7 */
            }; /* bitfield */
            volatile INT32 ProcessFlags;
        }; /* size: 0x0004 */
        CHAR BasePriority;
        CHAR QuantumReset;
        UINT8 Visited;
        union _KEXECUTE_OPTIONS Flags;
        UINT32 ThreadSeed[NumberOfProcessor];
        UINT16 IdealNode[NumberOfProcessor];
        UINT16 IdealGlobalNode;
        UINT16 Spare1;
#ifdef _X86_
        UINT16 IopmOffset;
        struct _KSCHEDULING_GROUP* SchedulingGroup;
#endif
        volatile union _KSTACK_COUNT StackCount;
        struct _LIST_ENTRY ProcessListEntry;
        UINT64 CycleTime;
        UINT64 ContextSwitches;
#ifdef _WIN64
        struct _KSCHEDULING_GROUP* SchedulingGroup;
#endif
        UINT32 FreezeCount;
        UINT32 KernelTime;
        UINT32 UserTime;
#ifdef _WIN64
        UINT16 LdtFreeSelectorHint;
        UINT16 LdtTableLength;
        union _KGDTENTRY64 LdtSystemDescriptor;
        VOID* LdtBaseAddress;
        struct _FAST_MUTEX LdtProcessLock;
        VOID* InstrumentationCallback;
#else
        VOID* VdmTrapcHandler;
#endif
    } KPROCESS, *PKPROCESS; /* size: 0x02c8 */ /* size: 0x00a0 */
    static_assert(sizeof(KPROCESS) == (sizeof(SIZE_T) == sizeof(UINT64) ? 0x02c8 : 0x00a0));



    typedef struct _EPROCESS
    {
        struct _KPROCESS Pcb;
        struct _EX_PUSH_LOCK ProcessLock;
#ifdef _X86_
        UINT32 Padding;
#endif
        union _LARGE_INTEGER CreateTime;
        struct _EX_RUNDOWN_REF RundownProtect;
        VOID* UniqueProcessId;
        struct _LIST_ENTRY ActiveProcessLinks;
        union
        {
            UINT32 Flags2;
            struct /* bitfield */
            {
                UINT32 JobNotReallyActive : 1; /* bit position: 0 */
                UINT32 AccountingFolded : 1; /* bit position: 1 */
                UINT32 NewProcessReported : 1; /* bit position: 2 */
                UINT32 ExitProcessReported : 1; /* bit position: 3 */
                UINT32 ReportCommitChanges : 1; /* bit position: 4 */
                UINT32 LastReportMemory : 1; /* bit position: 5 */
                UINT32 NoWakeCharge : 1; /* bit position: 6 */
                UINT32 HandleTableRundown : 1; /* bit position: 7 */
                UINT32 NeedsHandleRundown : 1; /* bit position: 8 */
                UINT32 RefTraceEnabled : 1; /* bit position: 9 */
                UINT32 NumaAware : 1; /* bit position: 10 */
                UINT32 EmptyJobEvaluated : 1; /* bit position: 11 */
                UINT32 DefaultPagePriority : 3; /* bit position: 12 */
                UINT32 PrimaryTokenFrozen : 1; /* bit position: 15 */
                UINT32 ProcessVerifierTarget : 1; /* bit position: 16 */
                UINT32 StackRandomizationDisabled : 1; /* bit position: 17 */
                UINT32 AffinityPermanent : 1; /* bit position: 18 */
                UINT32 AffinityUpdateEnable : 1; /* bit position: 19 */
                UINT32 PropagateNode : 1; /* bit position: 20 */
                UINT32 ExplicitAffinity : 1; /* bit position: 21 */
                UINT32 ProcessExecutionState : 2; /* bit position: 22 */
                UINT32 DisallowStrippedImages : 1; /* bit position: 24 */
                UINT32 HighEntropyASLREnabled : 1; /* bit position: 25 */
                UINT32 ExtensionPointDisable : 1; /* bit position: 26 */
                UINT32 ForceRelocateImages : 1; /* bit position: 27 */
                UINT32 ProcessStateChangeRequest : 2; /* bit position: 28 */
                UINT32 ProcessStateChangeInProgress : 1; /* bit position: 30 */
                UINT32 DisallowWin32kSystemCalls : 1; /* bit position: 31 */
            }; /* bitfield */
        }; /* size: 0x0004 */
        union
        {
            UINT32 Flags;
            struct /* bitfield */
            {
                UINT32 CreateReported : 1; /* bit position: 0 */
                UINT32 NoDebugInherit : 1; /* bit position: 1 */
                UINT32 ProcessExiting : 1; /* bit position: 2 */
                UINT32 ProcessDelete : 1; /* bit position: 3 */
                UINT32 Wow64SplitPages : 1; /* bit position: 4 */
                UINT32 VmDeleted : 1; /* bit position: 5 */
                UINT32 OutswapEnabled : 1; /* bit position: 6 */
                UINT32 Outswapped : 1; /* bit position: 7 */
                UINT32 ForkFailed : 1; /* bit position: 8 */
                UINT32 Wow64VaSpace4Gb : 1; /* bit position: 9 */
                UINT32 AddressSpaceInitialized : 2; /* bit position: 10 */
                UINT32 SetTimerResolution : 1; /* bit position: 12 */
                UINT32 BreakOnTermination : 1; /* bit position: 13 */
                UINT32 DeprioritizeViews : 1; /* bit position: 14 */
                UINT32 WriteWatch : 1; /* bit position: 15 */
                UINT32 ProcessInSession : 1; /* bit position: 16 */
                UINT32 OverrideAddressSpace : 1; /* bit position: 17 */
                UINT32 HasAddressSpace : 1; /* bit position: 18 */
                UINT32 LaunchPrefetched : 1; /* bit position: 19 */
                UINT32 Background : 1; /* bit position: 20 */
                UINT32 VmTopDown : 1; /* bit position: 21 */
                UINT32 ImageNotifyDone : 1; /* bit position: 22 */
                UINT32 PdeUpdateNeeded : 1; /* bit position: 23 */
                UINT32 VdmAllowed : 1; /* bit position: 24 */
                UINT32 CrossSessionCreate : 1; /* bit position: 25 */
                UINT32 ProcessInserted : 1; /* bit position: 26 */
                UINT32 DefaultIoPriority : 3; /* bit position: 27 */
                UINT32 ProcessSelfDelete : 1; /* bit position: 30 */
                UINT32 SetTimerResolutionLink : 1; /* bit position: 31 */
            }; /* bitfield */
        }; /* size: 0x0004 */
        SIZE_T ProcessQuotaUsage[2];
        SIZE_T ProcessQuotaPeak[2];
        SIZE_T PeakVirtualSize;
        SIZE_T VirtualSize;
        struct _LIST_ENTRY SessionProcessLinks;
        union
        {
            VOID* ExceptionPortData;
            SIZE_T ExceptionPortValue : sizeof(SIZE_T) * 8 - 3;
            SIZE_T ExceptionPortState : 3; /* bit position: 0 */
        }; /* size: 0x0008 */
        struct _EX_FAST_REF Token;
        SIZE_T WorkingSetPage;
        struct _EX_PUSH_LOCK AddressCreationLock;
        struct _ETHREAD* RotateInProgress;
        struct _ETHREAD* ForkInProgress;
        SIZE_T HardwareTrigger;
        struct _EJOB* volatile CommitChargeJob;
        struct _MM_AVL_TABLE* CloneRoot;
        volatile SIZE_T NumberOfPrivatePages;
        volatile SIZE_T NumberOfLockedPages;
        VOID* Win32Process;
        struct _EJOB* volatile Job;
        VOID* SectionObject;
        VOID* SectionBaseAddress;
        UINT32 Cookie;
#ifdef _X86_
        VOID* VdmObjects;
#endif
        struct _PAGEFAULT_HISTORY* WorkingSetWatch;
        VOID* Win32WindowStation;
        VOID* InheritedFromUniqueProcessId;
#ifdef _X86_
        VOID* LdtInformation;
#else
        VOID* Spare0;
#endif
        union
        {
            struct _EPROCESS* CreatorProcess;
            SIZE_T ConsoleHostProcess;
        };
        struct _PEB* Peb;
        VOID* Session;
        VOID* AweInfo;
        struct _EPROCESS_QUOTA_BLOCK* QuotaBlock;
        struct _HANDLE_TABLE* ObjectTable;
        VOID* DebugPort;
#ifdef _WIN64
        VOID* Wow64Process;
#else
        VOID* PaeTop;
#endif
        VOID* DeviceMap;
        VOID* EtwDataSource;
        UINT64 PageDirectoryPte;
        UINT8 ImageFileName[15];
        UINT8 PriorityClass;
        VOID* SecurityPort;
        struct _SE_AUDIT_PROCESS_CREATION_INFO SeAuditProcessCreationInfo;
        struct _LIST_ENTRY JobLinks;
        VOID* HighestUserAddress;
        struct _LIST_ENTRY ThreadListHead;
        volatile UINT32 ActiveThreads;
        UINT32 ImagePathHash;
        UINT32 DefaultHardErrorProcessing;
        INT32 LastThreadExitStatus;
        struct _EX_FAST_REF PrefetchTrace;
        struct _MM_AVL_TABLE* LockedPagesList;
        union _LARGE_INTEGER ReadOperationCount;
        union _LARGE_INTEGER WriteOperationCount;
        union _LARGE_INTEGER OtherOperationCount;
        union _LARGE_INTEGER ReadTransferCount;
        union _LARGE_INTEGER WriteTransferCount;
        union _LARGE_INTEGER OtherTransferCount;
        SIZE_T CommitChargeLimit;
        volatile SIZE_T CommitCharge;
        volatile SIZE_T CommitChargePeak;
        struct _MMSUPPORT Vm;
        struct _LIST_ENTRY MmProcessLinks;
        UINT32 ModifiedPageCount;
        INT32 ExitStatus;
        struct _MM_AVL_TABLE VadRoot;
        volatile SIZE_T VadPhysicalPages;
        SIZE_T VadPhysicalPagesLimit;
        struct _ALPC_PROCESS_CONTEXT AlpcContext;
        struct _LIST_ENTRY TimerResolutionLink;
        struct _PO_DIAG_STACK_RECORD* TimerResolutionStackRecord;
        UINT32 RequestedTimerResolution;
        UINT32 SmallestTimerResolution;
        union _LARGE_INTEGER ExitTime;
#ifdef _WIN64
        struct _INVERTED_FUNCTION_TABLE* InvertedFunctionTable;
        struct _EX_PUSH_LOCK InvertedFunctionTableLock;
#endif
        UINT32 ActiveThreadsHighWatermark;
        UINT32 LargePrivateVadCount;
        struct _EX_PUSH_LOCK ThreadListLock;
        VOID* WnfContext;
        SIZE_T SectionMappingSize;
        UINT8 SignatureLevel;
        UINT8 SectionSignatureLevel;
        UINT8 SpareByte20[2];
        UINT32 KeepAliveCounter;
        struct _PROCESS_DISK_COUNTERS* DiskCounters;
        UINT64 LastFreezeInterruptTime;
    } EPROCESS, *PEPROCESS; /* size: 0x0660 */ /* size: 0x02e8 */
    static_assert(sizeof(EPROCESS) == (sizeof(SIZE_T) == sizeof(UINT64) ? 0x0660 : 0x02e8));

}
