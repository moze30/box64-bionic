// SPDX-License-Identifier: MIT
#if !(defined(GO) && defined(GOM) && defined(GO2) && defined(DATA))
#error Meh...
#endif

GO(av_codec_get_tag, uFpu)
GO(av_demuxer_iterate, pFp)
GO(av_find_input_format, pFp)
GO(avformat_alloc_context, pFv)
GO(avformat_find_stream_info, iFpp)
GO(avformat_free_context, vFp)
GO(avformat_get_mov_audio_tags, pFv)
GO(avformat_get_mov_video_tags, pFv)
GO(avformat_get_riff_audio_tags, pFv)
GO(avformat_get_riff_video_tags, pFv)
GO(avformat_open_input, iFpppp)
GO(avformat_version, uFv)
GOM(avio_alloc_context, pFEpiipppp)
GO(avio_context_free, vFp)
GO(av_read_frame, iFpp)
GO(av_seek_frame, iFpiIi)
