// Copyright (c) 2008 The Board of Trustees of The Leland Stanford Junior University
// Copyright (c) 2011, 2012 Open Networking Foundation
// Copyright (c) 2012, 2013 Big Switch Networks, Inc.
// This library was generated by the LoxiGen Compiler.
// See the file LICENSE.txt which should have been included in the source distribution

// Automatically generated by LOXI from template of_class.java
// Do not modify

package org.projectfloodlight.openflow.protocol.ver15;

import org.projectfloodlight.openflow.protocol.*;
import org.projectfloodlight.openflow.protocol.action.*;
import org.projectfloodlight.openflow.protocol.actionid.*;
import org.projectfloodlight.openflow.protocol.bsntlv.*;
import org.projectfloodlight.openflow.protocol.errormsg.*;
import org.projectfloodlight.openflow.protocol.meterband.*;
import org.projectfloodlight.openflow.protocol.instruction.*;
import org.projectfloodlight.openflow.protocol.instructionid.*;
import org.projectfloodlight.openflow.protocol.match.*;
import org.projectfloodlight.openflow.protocol.stat.*;
import org.projectfloodlight.openflow.protocol.oxm.*;
import org.projectfloodlight.openflow.protocol.oxs.*;
import org.projectfloodlight.openflow.protocol.queueprop.*;
import org.projectfloodlight.openflow.types.*;
import org.projectfloodlight.openflow.util.*;
import org.projectfloodlight.openflow.exceptions.*;
import org.slf4j.Logger;
import org.slf4j.LoggerFactory;
import java.util.Set;
import com.google.common.collect.ImmutableSet;
import java.util.List;
import com.google.common.collect.ImmutableList;
import javax.annotation.Nonnull;
import io.netty.buffer.ByteBuf;
import com.google.common.hash.PrimitiveSink;
import com.google.common.hash.Funnel;

class OFPortDescVer15 implements OFPortDesc {
    private static final Logger logger = LoggerFactory.getLogger(OFPortDescVer15.class);
    // version: 1.5
    final static byte WIRE_VERSION = 6;
    final static int MINIMUM_LENGTH = 40;
    // maximum OF message length: 16 bit, unsigned
    final static int MAXIMUM_LENGTH = 0xFFFF;

        private final static OFPort DEFAULT_PORT_NO = OFPort.ANY;
        private final static MacAddress DEFAULT_HW_ADDR = MacAddress.NONE;
        private final static String DEFAULT_NAME = "";
        private final static Set<OFPortConfig> DEFAULT_CONFIG = ImmutableSet.<OFPortConfig>of();
        private final static Set<OFPortState> DEFAULT_STATE = ImmutableSet.<OFPortState>of();
        private final static List<OFPortDescProp> DEFAULT_PROPERTIES = ImmutableList.<OFPortDescProp>of();

    // OF message fields
    private final OFPort portNo;
    private final MacAddress hwAddr;
    private final String name;
    private final Set<OFPortConfig> config;
    private final Set<OFPortState> state;
    private final List<OFPortDescProp> properties;
//
    // Immutable default instance
    final static OFPortDescVer15 DEFAULT = new OFPortDescVer15(
        DEFAULT_PORT_NO, DEFAULT_HW_ADDR, DEFAULT_NAME, DEFAULT_CONFIG, DEFAULT_STATE, DEFAULT_PROPERTIES
    );

    // package private constructor - used by readers, builders, and factory
    OFPortDescVer15(OFPort portNo, MacAddress hwAddr, String name, Set<OFPortConfig> config, Set<OFPortState> state, List<OFPortDescProp> properties) {
        if(portNo == null) {
            throw new NullPointerException("OFPortDescVer15: property portNo cannot be null");
        }
        if(hwAddr == null) {
            throw new NullPointerException("OFPortDescVer15: property hwAddr cannot be null");
        }
        if(name == null) {
            throw new NullPointerException("OFPortDescVer15: property name cannot be null");
        }
        if(config == null) {
            throw new NullPointerException("OFPortDescVer15: property config cannot be null");
        }
        if(state == null) {
            throw new NullPointerException("OFPortDescVer15: property state cannot be null");
        }
        if(properties == null) {
            throw new NullPointerException("OFPortDescVer15: property properties cannot be null");
        }
        this.portNo = portNo;
        this.hwAddr = hwAddr;
        this.name = name;
        this.config = config;
        this.state = state;
        this.properties = properties;
    }

    // Accessors for OF message fields
    @Override
    public Set<OFPortFeatures> getAdvertised()throws UnsupportedOperationException {
        throw new UnsupportedOperationException("Property advertised not supported in version 1.5");
    }

    @Override
    public Set<OFPortConfig> getConfig() {
        return config;
    }

    @Override
    public Set<OFPortFeatures> getCurr()throws UnsupportedOperationException {
        throw new UnsupportedOperationException("Property curr not supported in version 1.5");
    }

    @Override
    public long getCurrSpeed()throws UnsupportedOperationException {
        throw new UnsupportedOperationException("Property currSpeed not supported in version 1.5");
    }

    @Override
    public MacAddress getHwAddr() {
        return hwAddr;
    }

    @Override
    public long getMaxSpeed()throws UnsupportedOperationException {
        throw new UnsupportedOperationException("Property maxSpeed not supported in version 1.5");
    }

    @Override
    public String getName() {
        return name;
    }

    @Override
    public Set<OFPortFeatures> getPeer()throws UnsupportedOperationException {
        throw new UnsupportedOperationException("Property peer not supported in version 1.5");
    }

    @Override
    public OFPort getPortNo() {
        return portNo;
    }

    @Override
    public List<OFPortDescProp> getProperties() {
        return properties;
    }

    @Override
    public Set<OFPortState> getState() {
        return state;
    }

    @Override
    public Set<OFPortFeatures> getSupported()throws UnsupportedOperationException {
        throw new UnsupportedOperationException("Property supported not supported in version 1.5");
    }

    @Override
    public OFVersion getVersion() {
        return OFVersion.OF_15;
    }



    /**
     * Returns true if the port is up, i.e., it's neither administratively
     * down nor link down. It currently does NOT take STP state into
     * consideration
     * @return whether the port is up
     */
    public boolean isEnabled() {
        return (!state.contains(OFPortState.LINK_DOWN) && !config.contains(OFPortConfig.PORT_DOWN));
    }

    /**
     * Returns the current generation ID of this port.
     *
     * The generationId is reported by the switch as a @{link OFPortDescProp} in
     * {@link OFPortDescStatsReply} and {@link OFPortStatus} messages. If the
     * current OFPortDesc does not contain a generation Id, returns U64.ZERO;
     *
     * For OpenFlow versions earlier than 1.4, always returns U64.ZERO;
     *
     * @return the generation ID or U64.NULL if not reported
     * @since 1.4
     */
     @Nonnull
     public U64 getBsnGenerationId() {
         for(OFPortDescProp prop: getProperties()) {
            if(prop instanceof OFPortDescPropBsnGenerationId) {
                return ((OFPortDescPropBsnGenerationId) prop).getGenerationId();
            }
         }
         return U64.ZERO;
     }

    public OFPortDesc.Builder createBuilder() {
        return new BuilderWithParent(this);
    }

    static class BuilderWithParent implements OFPortDesc.Builder {
        final OFPortDescVer15 parentMessage;

        // OF message fields
        private boolean portNoSet;
        private OFPort portNo;
        private boolean hwAddrSet;
        private MacAddress hwAddr;
        private boolean nameSet;
        private String name;
        private boolean configSet;
        private Set<OFPortConfig> config;
        private boolean stateSet;
        private Set<OFPortState> state;
        private boolean propertiesSet;
        private List<OFPortDescProp> properties;

        BuilderWithParent(OFPortDescVer15 parentMessage) {
            this.parentMessage = parentMessage;
        }

    @Override
    public Set<OFPortFeatures> getAdvertised()throws UnsupportedOperationException {
        throw new UnsupportedOperationException("Property advertised not supported in version 1.5");
    }

    @Override
    public OFPortDesc.Builder setAdvertised(Set<OFPortFeatures> advertised) throws UnsupportedOperationException {
            throw new UnsupportedOperationException("Property advertised not supported in version 1.5");
    }
    @Override
    public Set<OFPortConfig> getConfig() {
        return config;
    }

    @Override
    public OFPortDesc.Builder setConfig(Set<OFPortConfig> config) {
        this.config = config;
        this.configSet = true;
        return this;
    }
    @Override
    public Set<OFPortFeatures> getCurr()throws UnsupportedOperationException {
        throw new UnsupportedOperationException("Property curr not supported in version 1.5");
    }

    @Override
    public OFPortDesc.Builder setCurr(Set<OFPortFeatures> curr) throws UnsupportedOperationException {
            throw new UnsupportedOperationException("Property curr not supported in version 1.5");
    }
    @Override
    public long getCurrSpeed()throws UnsupportedOperationException {
        throw new UnsupportedOperationException("Property currSpeed not supported in version 1.5");
    }

    @Override
    public OFPortDesc.Builder setCurrSpeed(long currSpeed) throws UnsupportedOperationException {
            throw new UnsupportedOperationException("Property currSpeed not supported in version 1.5");
    }
    @Override
    public MacAddress getHwAddr() {
        return hwAddr;
    }

    @Override
    public OFPortDesc.Builder setHwAddr(MacAddress hwAddr) {
        this.hwAddr = hwAddr;
        this.hwAddrSet = true;
        return this;
    }
    @Override
    public long getMaxSpeed()throws UnsupportedOperationException {
        throw new UnsupportedOperationException("Property maxSpeed not supported in version 1.5");
    }

    @Override
    public OFPortDesc.Builder setMaxSpeed(long maxSpeed) throws UnsupportedOperationException {
            throw new UnsupportedOperationException("Property maxSpeed not supported in version 1.5");
    }
    @Override
    public String getName() {
        return name;
    }

    @Override
    public OFPortDesc.Builder setName(String name) {
        this.name = name;
        this.nameSet = true;
        return this;
    }
    @Override
    public Set<OFPortFeatures> getPeer()throws UnsupportedOperationException {
        throw new UnsupportedOperationException("Property peer not supported in version 1.5");
    }

    @Override
    public OFPortDesc.Builder setPeer(Set<OFPortFeatures> peer) throws UnsupportedOperationException {
            throw new UnsupportedOperationException("Property peer not supported in version 1.5");
    }
    @Override
    public OFPort getPortNo() {
        return portNo;
    }

    @Override
    public OFPortDesc.Builder setPortNo(OFPort portNo) {
        this.portNo = portNo;
        this.portNoSet = true;
        return this;
    }
    @Override
    public List<OFPortDescProp> getProperties() {
        return properties;
    }

    @Override
    public OFPortDesc.Builder setProperties(List<OFPortDescProp> properties) {
        this.properties = properties;
        this.propertiesSet = true;
        return this;
    }
    @Override
    public Set<OFPortState> getState() {
        return state;
    }

    @Override
    public OFPortDesc.Builder setState(Set<OFPortState> state) {
        this.state = state;
        this.stateSet = true;
        return this;
    }
    @Override
    public Set<OFPortFeatures> getSupported()throws UnsupportedOperationException {
        throw new UnsupportedOperationException("Property supported not supported in version 1.5");
    }

    @Override
    public OFPortDesc.Builder setSupported(Set<OFPortFeatures> supported) throws UnsupportedOperationException {
            throw new UnsupportedOperationException("Property supported not supported in version 1.5");
    }
    @Override
    public OFVersion getVersion() {
        return OFVersion.OF_15;
    }



        @Override
        public OFPortDesc build() {
                OFPort portNo = this.portNoSet ? this.portNo : parentMessage.portNo;
                if(portNo == null)
                    throw new NullPointerException("Property portNo must not be null");
                MacAddress hwAddr = this.hwAddrSet ? this.hwAddr : parentMessage.hwAddr;
                if(hwAddr == null)
                    throw new NullPointerException("Property hwAddr must not be null");
                String name = this.nameSet ? this.name : parentMessage.name;
                if(name == null)
                    throw new NullPointerException("Property name must not be null");
                Set<OFPortConfig> config = this.configSet ? this.config : parentMessage.config;
                if(config == null)
                    throw new NullPointerException("Property config must not be null");
                Set<OFPortState> state = this.stateSet ? this.state : parentMessage.state;
                if(state == null)
                    throw new NullPointerException("Property state must not be null");
                List<OFPortDescProp> properties = this.propertiesSet ? this.properties : parentMessage.properties;
                if(properties == null)
                    throw new NullPointerException("Property properties must not be null");

                //
                return new OFPortDescVer15(
                    portNo,
                    hwAddr,
                    name,
                    config,
                    state,
                    properties
                );
        }

    }

    static class Builder implements OFPortDesc.Builder {
        // OF message fields
        private boolean portNoSet;
        private OFPort portNo;
        private boolean hwAddrSet;
        private MacAddress hwAddr;
        private boolean nameSet;
        private String name;
        private boolean configSet;
        private Set<OFPortConfig> config;
        private boolean stateSet;
        private Set<OFPortState> state;
        private boolean propertiesSet;
        private List<OFPortDescProp> properties;

    @Override
    public Set<OFPortFeatures> getAdvertised()throws UnsupportedOperationException {
        throw new UnsupportedOperationException("Property advertised not supported in version 1.5");
    }

    @Override
    public OFPortDesc.Builder setAdvertised(Set<OFPortFeatures> advertised) throws UnsupportedOperationException {
            throw new UnsupportedOperationException("Property advertised not supported in version 1.5");
    }
    @Override
    public Set<OFPortConfig> getConfig() {
        return config;
    }

    @Override
    public OFPortDesc.Builder setConfig(Set<OFPortConfig> config) {
        this.config = config;
        this.configSet = true;
        return this;
    }
    @Override
    public Set<OFPortFeatures> getCurr()throws UnsupportedOperationException {
        throw new UnsupportedOperationException("Property curr not supported in version 1.5");
    }

    @Override
    public OFPortDesc.Builder setCurr(Set<OFPortFeatures> curr) throws UnsupportedOperationException {
            throw new UnsupportedOperationException("Property curr not supported in version 1.5");
    }
    @Override
    public long getCurrSpeed()throws UnsupportedOperationException {
        throw new UnsupportedOperationException("Property currSpeed not supported in version 1.5");
    }

    @Override
    public OFPortDesc.Builder setCurrSpeed(long currSpeed) throws UnsupportedOperationException {
            throw new UnsupportedOperationException("Property currSpeed not supported in version 1.5");
    }
    @Override
    public MacAddress getHwAddr() {
        return hwAddr;
    }

    @Override
    public OFPortDesc.Builder setHwAddr(MacAddress hwAddr) {
        this.hwAddr = hwAddr;
        this.hwAddrSet = true;
        return this;
    }
    @Override
    public long getMaxSpeed()throws UnsupportedOperationException {
        throw new UnsupportedOperationException("Property maxSpeed not supported in version 1.5");
    }

    @Override
    public OFPortDesc.Builder setMaxSpeed(long maxSpeed) throws UnsupportedOperationException {
            throw new UnsupportedOperationException("Property maxSpeed not supported in version 1.5");
    }
    @Override
    public String getName() {
        return name;
    }

    @Override
    public OFPortDesc.Builder setName(String name) {
        this.name = name;
        this.nameSet = true;
        return this;
    }
    @Override
    public Set<OFPortFeatures> getPeer()throws UnsupportedOperationException {
        throw new UnsupportedOperationException("Property peer not supported in version 1.5");
    }

    @Override
    public OFPortDesc.Builder setPeer(Set<OFPortFeatures> peer) throws UnsupportedOperationException {
            throw new UnsupportedOperationException("Property peer not supported in version 1.5");
    }
    @Override
    public OFPort getPortNo() {
        return portNo;
    }

    @Override
    public OFPortDesc.Builder setPortNo(OFPort portNo) {
        this.portNo = portNo;
        this.portNoSet = true;
        return this;
    }
    @Override
    public List<OFPortDescProp> getProperties() {
        return properties;
    }

    @Override
    public OFPortDesc.Builder setProperties(List<OFPortDescProp> properties) {
        this.properties = properties;
        this.propertiesSet = true;
        return this;
    }
    @Override
    public Set<OFPortState> getState() {
        return state;
    }

    @Override
    public OFPortDesc.Builder setState(Set<OFPortState> state) {
        this.state = state;
        this.stateSet = true;
        return this;
    }
    @Override
    public Set<OFPortFeatures> getSupported()throws UnsupportedOperationException {
        throw new UnsupportedOperationException("Property supported not supported in version 1.5");
    }

    @Override
    public OFPortDesc.Builder setSupported(Set<OFPortFeatures> supported) throws UnsupportedOperationException {
            throw new UnsupportedOperationException("Property supported not supported in version 1.5");
    }
    @Override
    public OFVersion getVersion() {
        return OFVersion.OF_15;
    }

//
        @Override
        public OFPortDesc build() {
            OFPort portNo = this.portNoSet ? this.portNo : DEFAULT_PORT_NO;
            if(portNo == null)
                throw new NullPointerException("Property portNo must not be null");
            MacAddress hwAddr = this.hwAddrSet ? this.hwAddr : DEFAULT_HW_ADDR;
            if(hwAddr == null)
                throw new NullPointerException("Property hwAddr must not be null");
            String name = this.nameSet ? this.name : DEFAULT_NAME;
            if(name == null)
                throw new NullPointerException("Property name must not be null");
            Set<OFPortConfig> config = this.configSet ? this.config : DEFAULT_CONFIG;
            if(config == null)
                throw new NullPointerException("Property config must not be null");
            Set<OFPortState> state = this.stateSet ? this.state : DEFAULT_STATE;
            if(state == null)
                throw new NullPointerException("Property state must not be null");
            List<OFPortDescProp> properties = this.propertiesSet ? this.properties : DEFAULT_PROPERTIES;
            if(properties == null)
                throw new NullPointerException("Property properties must not be null");


            return new OFPortDescVer15(
                    portNo,
                    hwAddr,
                    name,
                    config,
                    state,
                    properties
                );
        }

    }


    final static Reader READER = new Reader();
    static class Reader implements OFMessageReader<OFPortDesc> {
        @Override
        public OFPortDesc readFrom(ByteBuf bb) throws OFParseError {
            int start = bb.readerIndex();
            OFPort portNo = OFPort.read4Bytes(bb);
            int length = U16.f(bb.readShort());
            if(length < MINIMUM_LENGTH)
                throw new OFParseError("Wrong length: Expected to be >= " + MINIMUM_LENGTH + ", was: " + length);
            if(bb.readableBytes() + (bb.readerIndex() - start) < length) {
                // Buffer does not have all data yet
                bb.readerIndex(start);
                return null;
            }
            if(logger.isTraceEnabled())
                logger.trace("readFrom - length={}", length);
            // pad: 2 bytes
            bb.skipBytes(2);
            MacAddress hwAddr = MacAddress.read6Bytes(bb);
            // pad: 2 bytes
            bb.skipBytes(2);
            String name = ChannelUtils.readFixedLengthString(bb, 16);
            Set<OFPortConfig> config = OFPortConfigSerializerVer15.readFrom(bb);
            Set<OFPortState> state = OFPortStateSerializerVer15.readFrom(bb);
            List<OFPortDescProp> properties = ChannelUtils.readList(bb, length - (bb.readerIndex() - start), OFPortDescPropVer15.READER);

            OFPortDescVer15 portDescVer15 = new OFPortDescVer15(
                    portNo,
                      hwAddr,
                      name,
                      config,
                      state,
                      properties
                    );
            if(logger.isTraceEnabled())
                logger.trace("readFrom - read={}", portDescVer15);
            return portDescVer15;
        }
    }

    public void putTo(PrimitiveSink sink) {
        FUNNEL.funnel(this, sink);
    }

    final static OFPortDescVer15Funnel FUNNEL = new OFPortDescVer15Funnel();
    static class OFPortDescVer15Funnel implements Funnel<OFPortDescVer15> {
        private static final long serialVersionUID = 1L;
        @Override
        public void funnel(OFPortDescVer15 message, PrimitiveSink sink) {
            message.portNo.putTo(sink);
            // FIXME: skip funnel of length
            // skip pad (2 bytes)
            message.hwAddr.putTo(sink);
            // skip pad (2 bytes)
            sink.putUnencodedChars(message.name);
            OFPortConfigSerializerVer15.putTo(message.config, sink);
            OFPortStateSerializerVer15.putTo(message.state, sink);
            FunnelUtils.putList(message.properties, sink);
        }
    }


    public void writeTo(ByteBuf bb) {
        WRITER.write(bb, this);
    }

    final static Writer WRITER = new Writer();
    static class Writer implements OFMessageWriter<OFPortDescVer15> {
        @Override
        public void write(ByteBuf bb, OFPortDescVer15 message) {
            int startIndex = bb.writerIndex();
            message.portNo.write4Bytes(bb);
            // length is length of variable message, will be updated at the end
            int lengthIndex = bb.writerIndex();
            bb.writeShort(U16.t(0));

            // pad: 2 bytes
            bb.writeZero(2);
            message.hwAddr.write6Bytes(bb);
            // pad: 2 bytes
            bb.writeZero(2);
            ChannelUtils.writeFixedLengthString(bb, message.name, 16);
            OFPortConfigSerializerVer15.writeTo(bb, message.config);
            OFPortStateSerializerVer15.writeTo(bb, message.state);
            ChannelUtils.writeList(bb, message.properties);

            // update length field
            int length = bb.writerIndex() - startIndex;
            if (length > MAXIMUM_LENGTH) {
                throw new IllegalArgumentException("OFPortDescVer15: message length (" + length + ") exceeds maximum (0xFFFF)");
            }
            bb.setShort(lengthIndex, length);

        }
    }

    @Override
    public String toString() {
        StringBuilder b = new StringBuilder("OFPortDescVer15(");
        b.append("portNo=").append(portNo);
        b.append(", ");
        b.append("hwAddr=").append(hwAddr);
        b.append(", ");
        b.append("name=").append(name);
        b.append(", ");
        b.append("config=").append(config);
        b.append(", ");
        b.append("state=").append(state);
        b.append(", ");
        b.append("properties=").append(properties);
        b.append(")");
        return b.toString();
    }

    @Override
    public boolean equals(Object obj) {
        if (this == obj)
            return true;
        if (obj == null)
            return false;
        if (getClass() != obj.getClass())
            return false;
        OFPortDescVer15 other = (OFPortDescVer15) obj;

        if (portNo == null) {
            if (other.portNo != null)
                return false;
        } else if (!portNo.equals(other.portNo))
            return false;
        if (hwAddr == null) {
            if (other.hwAddr != null)
                return false;
        } else if (!hwAddr.equals(other.hwAddr))
            return false;
        if (name == null) {
            if (other.name != null)
                return false;
        } else if (!name.equals(other.name))
            return false;
        if (config == null) {
            if (other.config != null)
                return false;
        } else if (!config.equals(other.config))
            return false;
        if (state == null) {
            if (other.state != null)
                return false;
        } else if (!state.equals(other.state))
            return false;
        if (properties == null) {
            if (other.properties != null)
                return false;
        } else if (!properties.equals(other.properties))
            return false;
        return true;
    }

    @Override
    public int hashCode() {
        final int prime = 31;
        int result = 1;

        result = prime * result + ((portNo == null) ? 0 : portNo.hashCode());
        result = prime * result + ((hwAddr == null) ? 0 : hwAddr.hashCode());
        result = prime * result + ((name == null) ? 0 : name.hashCode());
        result = prime * result + ((config == null) ? 0 : config.hashCode());
        result = prime * result + ((state == null) ? 0 : state.hashCode());
        result = prime * result + ((properties == null) ? 0 : properties.hashCode());
        return result;
    }

}
