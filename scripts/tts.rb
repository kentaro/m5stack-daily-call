require "google/cloud/text_to_speech"

text_to_speech_client = Google::Cloud::TextToSpeech.new
text = ARGV.shift
input = { text: text }
language_code = "ja-JP"
voice = { language_code: language_code, name: "ja-JP-Wavenet-C" }
audio_encoding = :MP3
audio_config = { audio_encoding: audio_encoding }
response = text_to_speech_client.synthesize_speech(input, voice, audio_config)
puts response.audio_content
