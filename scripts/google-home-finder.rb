require 'resolv'                                                           

mdns = Resolv::MDNS.new
mdns.timeouts = 10
mdns.each_address('_googlecast._tcp.local.') do |a|
  p a
end
