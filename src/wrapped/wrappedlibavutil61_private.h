// SPDX-License-Identifier: MIT
#if !(defined(GO) && defined(GOM) && defined(GO2) && defined(DATA))
#error Meh...
#endif

GO(av_dict_get, pFpppi)
GO(av_get_pix_fmt_name, pFi)
GOM(av_log_set_callback, vFEp)
GO(av_rescale_q_rnd, IFIUUu)    // Both U are AVRational: struct with 2 ints
GO(av_strerror, iFipL)
GO(avutil_version, uFv)
