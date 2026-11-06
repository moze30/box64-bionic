// SPDX-License-Identifier: MIT
#if !(defined(GO) && defined(GOM) && defined(GO2) && defined(DATA))
#error Meh...
#endif

GO(av_bsf_alloc, iFpp)
GO(av_bsf_flush, vFp)
GO(av_bsf_free, vFp)
GO(av_bsf_get_by_name, pFp)
GO(av_bsf_get_null_filter, iFp)     // winedmo drops the return value, kept as declared in the 58 wrapper
GO(av_bsf_init, iFp)
GO(av_bsf_receive_packet, iFpp)
GO(av_bsf_send_packet, iFpp)
GO(avcodec_get_name, pFu)
GO(avcodec_parameters_copy, iFpp)
GO(av_get_bits_per_sample, iFu)
GO(av_packet_alloc, pFv)
GO(av_packet_free, vFp)
